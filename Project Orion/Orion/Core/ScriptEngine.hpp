#ifndef _SCRIPTENGINE_HPP_
#define _SCRIPTENGINE_HPP_

// Include the lua headers (the extern "C" is a requirement because we're
// using C++ and lua has been compiled as C code)
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <luabind/luabind.hpp>
#include <string>
#include "ScriptingDefs.hpp"

using namespace Orion::Game;

namespace Orion
{
	class ScriptEngine
	{
	public:
		static ScriptEngine& getInstance()
		{
			static ScriptEngine instance;
			return instance;
		}

		void Execute(std::string script)
		{
			luaL_dofile(mLuaState, script.c_str());
		}

	private:
		ScriptEngine()
		{
			mLuaState = luaL_newstate();

			// Connect LuaBind to this lua state
			luabind::open(mLuaState);

			// add player class
			luabind::module(mLuaState)[
				luabind::class_<Player>("Player")
					.def("GetWeaponId", &Player::GetWeaponId)
					.def("FireProjectile", &Player::FireProjectile)
					.def("FireProjectileWithDelay", &Player::FireProjectileWithDelay)
					.def("SetAimpoint", &Player::SetAimpoint)
			];

			// add enemy class
			luabind::module(mLuaState)[
				luabind::class_<Enemy>("Enemy")
					.def("GetX", &Enemy::GetX)
					.def("GetY", &Enemy::GetY)
			];

			luabind::module(mLuaState)[
				luabind::def("GetPlayer", GetPlayer)
			];

			luabind::module(mLuaState)[
				luabind::def("GetEnemy", GetEnemy)
			];
		}

		~ScriptEngine()
		{
			lua_close(mLuaState);
		}

		ScriptEngine(ScriptEngine const&);
		void operator=(ScriptEngine const&);

		lua_State*	mLuaState;
	};
}

#endif //_SCRIPTENGINE_HPP_