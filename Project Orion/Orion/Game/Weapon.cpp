#include "Weapon.hpp"

namespace Orion
{
	namespace Game
	{
		Weapon::Weapon(int id, string name, int minLevel)
		{
			mId = id;
			mName = name;
			mMinimumLevel = minLevel;
		}

		Weapon::~Weapon()
		{

		}

		int Weapon::GetId()
		{
			return mId;
		}

		string Weapon::GetName()
		{
			return mName;
		}

		int Weapon::GetMinimumLevel()
		{
			return mMinimumLevel;
		}

		shared_ptr<Projectile> Weapon::GetProjectile()
		{
			return mProjectile;
		}

		void Weapon::SetProjectile(shared_ptr<Projectile> projectile)
		{
			mProjectile = projectile;
		}
	}
}