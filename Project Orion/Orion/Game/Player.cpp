#include "Player.hpp"

namespace Orion
{
	namespace Game
	{
		Player::Player(std::string ref)
		{
			mSprite = make_shared<Sprite>(ref);
		}

		Player::~Player()
		{

		}

		bool Player::IsAlive()
		{
			return mSprite->IsAlive();
		}

		int Player::Count()
		{
			return 1;
		}

		void Player::Update(sf::Time& deltaTime)
		{
			mSprite->Update(deltaTime);
		}

		void Player::Draw(sf::RenderWindow& window)
		{
			mSprite->Draw(window);
		}

		void Player::SetWeapon(shared_ptr<Weapon> weapon, int wpnType)
		{
			switch (wpnType)
			{
			case WEAPON_TYPE_ROCKET:
				mRocketBattery = weapon;
				break;
			case WEAPON_TYPE_LASER:
				mLaserTurrent = weapon;
				break;
			case WEAPON_TYPE_RAILGUN:
				mRailGun = weapon;
				break;
			}
		}

		int Player::GetWeaponId(int weaponType)
		{
			int weaponId = -1;

			switch (weaponType)
			{
			case WEAPON_TYPE_ROCKET:
				if (mRocketBattery != nullptr)
					weaponId = mRocketBattery->GetId();
				break;

			case WEAPON_TYPE_LASER:
				if (mLaserTurrent != nullptr)
					weaponId = mLaserTurrent->GetId();
				break;

			case WEAPON_TYPE_RAILGUN:
				if (mRailGun != nullptr)
					weaponId = mRailGun->GetId();
				break;
			}

			return weaponId;
		}

		void Player::FireProjectile(int wpnType)
		{
			switch (wpnType)
			{
			case WEAPON_TYPE_ROCKET:
				/*auto projectile = mRocketBattery->GetProjectile()->Clone();
				projectile->SetPosition(mSprite->GetPosition());
				projectile->SetVelocity(sf::Vector2f(projectile->GetSpeed(), 0.0f));
				projectile->SetRotation(mSprite->GetRotation());
				projectile->SetZOrder(50);
				GetParent()->Add(projectile);*/
				auto rocketEvent = make_shared<FireProjectileEvent>(mRocketBattery,
																	GetParent(),
																	mSprite->GetPosition(),
																	mSprite->GetRotation(),
																	0.0f);
				EventQueue::getInstance().Add(rocketEvent);
				break;
			}
		}

		void Player::FireProjectileWithDelay(int wpnType, float delay)
		{
			switch (wpnType)
			{
			case WEAPON_TYPE_ROCKET:
				auto rocketEvent = make_shared<FireProjectileEvent>(mRocketBattery,
					GetParent(),
					mSprite->GetPosition(),
					mSprite->GetRotation(),
					delay);
				EventQueue::getInstance().Add(rocketEvent);
				break;
			}
		}

		shared_ptr<Sprite> Player::GetSprite()
		{
			return mSprite;
		}

		void Player::Add(shared_ptr<SceneNode> node)
		{
			return;
		}
	}
}