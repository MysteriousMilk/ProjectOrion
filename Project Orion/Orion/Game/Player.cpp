#include "Player.hpp"

namespace Orion
{
	namespace Game
	{
		Player::Player(std::string ref)
		{
			mSprite = make_shared<Sprite>(ref);
			mFireSlot = 0;
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

		void Player::AddWeapon(shared_ptr<Weapon> weapon, int wpnType)
		{
			switch (wpnType)
			{
			case WEAPON_TYPE_ROCKET:
				mRocketBatteryList.push_back(weapon);
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
				if (mRocketBatteryList.size() > 0)
					weaponId = mRocketBatteryList[0]->GetId();
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

		void Player::FireProjectile(int wpnType, float aimpointx, float aimpointy)
		{
			switch (wpnType)
			{
			case WEAPON_TYPE_ROCKET:
				if (mRocketBatteryList.size() > 0)
				{
					if (mFireSlot == mRocketBatteryList.size())
						mFireSlot = 0;

					sf::Vector2f finalAimpoint(aimpointx, aimpointy);
					sf::Vector2f initialAimpoint(aimpointx, aimpointy - 400.0f);

					auto rocketEvent = make_shared<FireProjectileEvent>(mRocketBatteryList[mFireSlot],
						GetParent(),
						mSprite->GetPosition(),
						initialAimpoint,
						finalAimpoint,
						0.0f);
					EventQueue::getInstance().Add(rocketEvent);

					mFireSlot++;
				}
				break;
			}
		}

		void Player::FireProjectileWithDelay(int wpnType, float aimpointx, float aimpointy, float delay)
		{
			switch (wpnType)
			{
			case WEAPON_TYPE_ROCKET:
				if (mRocketBatteryList.size() > 0)
				{
					if (mFireSlot == mRocketBatteryList.size())
						mFireSlot = 0;

					sf::Vector2f finalAimpoint(aimpointx, aimpointy);
					sf::Vector2f initialAimpoint;
					
					if (mRocketBatteryList[mFireSlot]->GetRelativeLocation().y < 0)
					{
						initialAimpoint.x = aimpointx;
						initialAimpoint.y = aimpointy - 400.0f;
					}
					else
					{
						initialAimpoint.x = aimpointx;
						initialAimpoint.y = aimpointy + 400.0f;
					}


					sf::Vector2f position;
					position.x = mSprite->GetPosition().x + mRocketBatteryList[mFireSlot]->GetRelativeLocation().x;
					position.y = mSprite->GetPosition().y + mRocketBatteryList[mFireSlot]->GetRelativeLocation().y;

					auto rocketEvent = make_shared<FireProjectileEvent>(mRocketBatteryList[mFireSlot],
						GetParent(),
						position,
						initialAimpoint,
						finalAimpoint,
						delay);
					EventQueue::getInstance().Add(rocketEvent);

					mFireSlot++;
				}
				break;
			}
		}

		void Player::SetAimpoint(float x, float y)
		{
			mAimpoint.x = x;
			mAimpoint.y = y;
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