#ifndef _PROJECTILE_HPP_
#define _PROJECTILE_HPP_

#include <string>
#include "../Core/Sprite.hpp"
#include "../Utilities/Math.hpp"

using namespace std;
using namespace Orion::Utilities;

namespace Orion
{
	namespace Game
	{
		class Projectile : public Sprite
		{
		public:
			Projectile(string ref) : Sprite(ref) {}
			Projectile(int id, string name, string filename, string ref, int wpnId, float speed, float updateDelay, const sf::Vector2f& initialAimpoint, const sf::Vector2f& finalAimpoint)
				: Sprite(filename, ref)
			{
				mId = id;
				mName = name;
				mFilename = filename;
				mRef = ref;
				mWpnId = wpnId;
				mSpeed = speed;
				mAimpointUpdateDelayMs = updateDelay;
				mCurrentAimpoint = initialAimpoint;
				mFinalAimpoint = finalAimpoint;

				mHasFired = false;
				mGuidanceOn = false;
				mAimpointUpdated = false;
				mTimeSinceLast = 0.0f;
				mElapsed = 0.0f;
			}

			~Projectile() {}

			int		GetId() { return mId; }
			string	GetName() { return mName; }
			string	GetFilename() { return mFilename; }
			string	GetReference() { return mRef; }
			int		GetWeaponId() { return mWpnId; }
			float	GetSpeed() { return mSpeed; }

			void SetCurrentAimpoint(const sf::Vector2f& aimpoint)
			{
				mCurrentAimpoint = aimpoint;
			}

			void SetFinalAimpoint(const sf::Vector2f& aimpoint)
			{
				mFinalAimpoint = aimpoint;
			}

			void Fire()
			{
				mHasFired = true;
				mGuidanceOn = true;

				UpdateAngle();
				SetRotation(mDesiredAngle);
			}

			shared_ptr<Projectile> Clone()
			{
				auto clone = make_shared<Projectile>(mId, mName, mFilename, mRef, mWpnId, mSpeed, mAimpointUpdateDelayMs, mCurrentAimpoint, mFinalAimpoint);
				clone->SetPosition(this->GetPosition());
				clone->SetVelocity(this->GetVelocity());
				clone->SetAlive(this->IsAlive());
				clone->SetColor(this->GetColor());
				clone->SetOrigin(this->GetOrigin());
				clone->SetRotation(this->GetRotation());
				clone->SetScale(this->GetScale().x, this->GetScale().y);
				clone->SetZOrder(this->GetZOrder());
				return clone;
			}

			void UpdateAngle()
			{
				// calculate angle
				double deltax = mCurrentAimpoint.x - GetPosition().x;
				double deltay = mCurrentAimpoint.y - GetPosition().y;

				mDesiredAngle = Math::ToDegrees(atan2(deltay, deltax)) + 90;
			}

			void Update(sf::Time& deltaTime)
			{
				mTimeSinceLast = deltaTime.asMilliseconds() - mTimeSinceLast;

				sf::IntRect screen(0, 0, 1280, 720);
				if (!screen.contains((int)this->GetPosition().x, (int)this->GetPosition().y))
					SetAlive(false);

				if (mHasFired)
				{
					if (mElapsed > mAimpointUpdateDelayMs)
					{
						mCurrentAimpoint = mFinalAimpoint;
						mElapsed = 0;
						mAimpointUpdated = true;

						UpdateAngle();
					}
					else
					{
						mElapsed += mTimeSinceLast;
					}

					if ((GetRotation() > mDesiredAngle + 1) || (GetRotation() < mDesiredAngle - 1))
					{
						if (mGuidanceOn)
						{
							if (mDesiredAngle > GetRotation())
								SetRotation(GetRotation() + 0.25f);
							else
								SetRotation(GetRotation() - 0.25f);
						}
					}
					else
					{
						if (mAimpointUpdated)
							mGuidanceOn = false;
					}

					float velx = (float)(cos(Math::ToRadians(GetRotation() - 90.0f)) * mSpeed);
					float vely = (float)(sin(Math::ToRadians(GetRotation() - 90.0f)) * mSpeed);
					SetVelocity(sf::Vector2f(velx, vely));
				}

				Sprite::Update(deltaTime);
			}

		private:
			int				mId;
			string			mName;
			string			mFilename;
			string			mRef;
			int				mWpnId;
			float			mSpeed;
			float			mElapsed;
			float			mTimeSinceLast;
			float			mAimpointUpdateDelayMs;

			float			mDesiredAngle;
			sf::Vector2f	mFinalAimpoint;
			sf::Vector2f	mCurrentAimpoint;

			bool			mHasFired;
			bool			mAimpointUpdated;
			bool			mGuidanceOn;
		};
	}
}

#endif //_PROJECTILE_HPP_