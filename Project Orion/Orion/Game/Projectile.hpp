#ifndef _PROJECTILE_HPP_
#define _PROJECTILE_HPP_

#include <string>
#include "../Core/Sprite.hpp"

using namespace std;

namespace Orion
{
	namespace Game
	{
		class Projectile : public Sprite
		{
		public:
			Projectile(string ref) : Sprite(ref) {}
			Projectile(int id, string name, string filename, string ref, int wpnId, float speed) : Sprite(filename, ref)
			{
				mId = id;
				mName = name;
				mFilename = filename;
				mRef = ref;
				mWpnId = wpnId;
				mSpeed = speed;
			}

			~Projectile() {}

			int		GetId() { return mId; }
			string	GetName() { return mName; }
			string	GetFilename() { return mFilename; }
			string	GetReference() { return mRef; }
			int		GetWeaponId() { return mWpnId; }
			float	GetSpeed() { return mSpeed; }

			shared_ptr<Projectile> Clone()
			{
				auto clone = make_shared<Projectile>(mId, mName, mFilename, mRef, mWpnId, mSpeed);
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

			void Update(sf::Time& deltaTime)
			{
				sf::IntRect screen(0, 0, 1280, 720);
				if (!screen.contains((int)this->GetPosition().x, (int)this->GetPosition().y))
					SetAlive(false);

				Sprite::Update(deltaTime);
			}

		private:
			int		mId;
			string	mName;
			string	mFilename;
			string	mRef;
			int		mWpnId;
			float	mSpeed;
		};
	}
}

#endif //_PROJECTILE_HPP_