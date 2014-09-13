#ifndef _FIREPROJECTILEEVENT_HPP_
#define _FIREPROJECTILEEVENT_HPP_

#include "GenericEvent.hpp"
#include "EventQueue.hpp"
#include "..\Game\Weapon.hpp"
#include "SFML\Graphics.hpp"

using namespace std;
using namespace sf;
using namespace Orion::Game;

namespace Orion
{
	namespace Event
	{
		class FireProjectileEvent : public GenericEvent
		{
		public:
			FireProjectileEvent(shared_ptr<Weapon> weapon, SceneNode* node, Vector2f position, float rotation, float delay)
			{
				mDrawNode = node;
				mWeapon = weapon;
				mPosition = position;
				mRotation = rotation;
				mTriggerTimeSec = EventQueue::getInstance().GetElapsed() + delay;
			}

			void Execute()
			{
				auto projectile = mWeapon->GetProjectile()->Clone();
				projectile->SetPosition(mPosition);
				projectile->SetVelocity(sf::Vector2f(projectile->GetSpeed(), 0.0f));
				projectile->SetRotation(mRotation);
				projectile->SetZOrder(50);
				mDrawNode->Add(projectile);
			}

		private:
			shared_ptr<Weapon>	mWeapon;
			SceneNode*			mDrawNode;
			Vector2f			mPosition;
			float				mRotation;
		};
	}
}

#endif // _FIREPRJECTILEEVENT_HPP_