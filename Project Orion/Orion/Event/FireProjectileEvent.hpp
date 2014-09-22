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
			FireProjectileEvent(shared_ptr<Weapon> weapon, SceneNode* node, Vector2f position, Vector2f initialAim, Vector2f finalAim, float delay)
			{
				mDrawNode = node;
				mWeapon = weapon;
				mPosition = position;
				mFinalAim = finalAim;
				mCurrAim = initialAim;
				mTriggerTimeSec = EventQueue::getInstance().GetElapsed() + delay;
			}

			void Execute()
			{
				auto projectile = mWeapon->GetProjectile()->Clone();
				projectile->SetPosition(mPosition);
				projectile->SetVelocity(sf::Vector2f(projectile->GetSpeed(), 0.0f));
				projectile->SetRotation(0.0f);
				projectile->SetZOrder(50);
				projectile->SetCurrentAimpoint(mCurrAim);
				projectile->SetFinalAimpoint(mFinalAim);
				projectile->Fire();
				mDrawNode->Add(projectile);
			}

		private:
			shared_ptr<Weapon>	mWeapon;
			SceneNode*			mDrawNode;
			Vector2f			mPosition;
			Vector2f			mFinalAim;
			Vector2f			mCurrAim;
		};
	}
}

#endif // _FIREPRJECTILEEVENT_HPP_