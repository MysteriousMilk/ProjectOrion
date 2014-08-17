#ifndef _ORION_HPP_
#define _ORION_HPP_

#include "Types.hpp"
#include "Resources\ResourceManager.hpp"
#include "Core\SceneNode.hpp"
#include "Core\Sprite.hpp"
#include "Core\Layer.hpp"
#include "Core\Scene.hpp"
#include "Game\Projectile.hpp"
#include "Game\Weapon.hpp"
#include "Game\Game.hpp"
#include "Game\Player.hpp"
#include "Factories\WeaponFactory.hpp"

using namespace Orion::Game;

namespace Orion
{
	class Engine
	{
	public:
		static Engine& getInstance()
		{
			static Engine instance;
			return instance;
		}

		void RegisterGame(std::shared_ptr<Orion::Game::Game> game)
		{
			mCurrentGame = game;
		}

		std::shared_ptr<Orion::Game::Game> GetCurrentGame()
		{
			return mCurrentGame;
		}

		void RegisterPlayer(Player* player)
		{
			mPlayer = player;
		}

		Player* GetPlayer()
		{
			return mPlayer;
		}

	private:
		Engine()
		{
			mCurrentGame = nullptr;
			mPlayer = nullptr;
		}

		~Engine() {};

		Engine(Engine const&);
		void operator=(Engine const&);

		std::shared_ptr<Orion::Game::Game> mCurrentGame;
		Player* mPlayer;
	};
}

#endif