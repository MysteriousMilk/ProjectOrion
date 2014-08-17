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
			];

			luabind::module(mLuaState)[
				luabind::def("GetPlayer", GetPlayer)
			];
		}

		~ScriptEngine()
		{
			lua_close(mLuaState);
		}

		void Execute(std::string script)
		{
			luaL_dofile(mLuaState, script.c_str());
		}

	private:
		lua_State*	mLuaState;
	};
}

#endif //_SCRIPTENGINE_HPP_