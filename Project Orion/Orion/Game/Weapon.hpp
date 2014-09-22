#ifndef _WEAPON_HPP_
#define _WEAPON_HPP_

#include <string>
#include "Projectile.hpp"

using namespace std;

namespace Orion
{
	namespace Game
	{
		const int WEAPON_TYPE_ROCKET = 1;
		const int WEAPON_TYPE_LASER = 2;
		const int WEAPON_TYPE_RAILGUN = 3;

		class Weapon
		{
		public:
			Weapon(int, string, int);
			~Weapon();

			int						GetId();
			string					GetName();
			int						GetMinimumLevel();
			shared_ptr<Projectile>	GetProjectile();
			void					SetProjectile(shared_ptr<Projectile>);
			sf::Vector2f&			GetRelativeLocation();
			void					SetRelativeLocation(const sf::Vector2f&);

		private:
			int						mId;
			string					mName;
			int						mMinimumLevel;
			sf::Vector2f			mRelLocation;

			shared_ptr<Projectile>	mProjectile;
		};
	}
}

#endif //_WEAPON_HPP_