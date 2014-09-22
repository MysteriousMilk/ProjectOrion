#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <SFML\System.hpp>
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
			void	FireProjectile(int, float, float);
			void	FireProjectileWithDelay(int, float, float, float);
			void	SetAimpoint(float, float);

			shared_ptr<Sprite> GetSprite();
			void	AddWeapon(shared_ptr<Weapon>, int);

			bool	IsAlive();
			int		Count();
			void	Update(sf::Time&);
			void	Draw(sf::RenderWindow&);
			void	Add(shared_ptr<SceneNode>);

		private:
			shared_ptr<Sprite>			mSprite;
			vector<shared_ptr<Weapon>>	mRocketBatteryList;
			shared_ptr<Weapon>			mLaserTurrent;
			shared_ptr<Weapon>			mRailGun;

			sf::Vector2f		mAimpoint;

			sf::Clock			mTimer;
			int					mFireSlot;
		};
	}
}

#endif //_PLAYER_HPP_