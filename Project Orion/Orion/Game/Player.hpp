#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "../Core/Sprite.hpp"
#include "../Event/EventQueue.hpp"
#include "../Event/FireProjectileEvent.hpp"
#include "Weapon.hpp"
#include "Game.hpp"

using namespace Orion::Event;

namespace Orion
{
	namespace Game
	{
		class Player : public SceneNode
		{
		public:
			Player(std::string);
			~Player();

			int		GetWeaponId(int);
			void	FireProjectile(int);
			void	FireProjectileWithDelay(int, float);

			shared_ptr<Sprite> GetSprite();
			void	SetWeapon(shared_ptr<Weapon>, int);

			bool	IsAlive();
			int		Count();
			void	Update(sf::Time&);
			void	Draw(sf::RenderWindow&);
			void	Add(shared_ptr<SceneNode>);

		private:
			shared_ptr<Sprite> mSprite;
			shared_ptr<Weapon> mRocketBattery;
			shared_ptr<Weapon> mLaserTurrent;
			shared_ptr<Weapon> mRailGun;

			sf::Clock			mTimer;
		};
	}
}

#endif //_PLAYER_HPP_