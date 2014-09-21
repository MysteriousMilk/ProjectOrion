#ifndef _ROCKETPROJECTILE_H_
#define _ROCKETPROJECTILE_H_

#include <math.h>
#include "Projectile.hpp"
#include "../Utilities/Math.hpp"

using namespace Orion::Utilities;

namespace Orion
{
	namespace Game
	{
		class RocketProjectile : public Projectile
		{
		public:
			RocketProjectile(string ref) : Projectile(ref) {}
			RocketProjectile(int id, string name, string filename, string ref, int wpnId, float speed)
				: Projectile(id, name, filename, ref, wpnId, speed)
			{
				mAimpoint.x = 0;
				mAimpoint.y = 0;
			}

			const sf::Vector2f& GetAimpoint()
			{
				return mAimpoint;
			}

			void SetAimpoint(float x, float y)
			{
				mAimpoint.x = x;
				mAimpoint.y - y;
			}

			void Update(sf::Time& deltaTime)
			{
				Projectile::Update(deltaTime);
			}

		private:
			sf::Vector2f mAimpoint;
		};
	}
}

#endif // _ROCKETPROJECTILE_H_