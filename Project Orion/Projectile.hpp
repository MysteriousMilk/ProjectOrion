#ifndef _PROJECTILE_HPP_
#define _PROJECTILE_HPP_

#include "Sprite.hpp"

namespace Orion
{
	class Projectile : public Sprite
	{
	public:
		Projectile(std::string ref) : Sprite(ref) {};
		~Projectile() {};

		void Update(sf::Time& deltaTime)
		{
			sf::IntRect screen(0, 0, 1280, 720);
			if (!screen.contains(this->GetPosition().x, this->GetPosition().y))
				SetAlive(false);

			Sprite::Update(deltaTime);
		}
	};
}

#endif //_PROJECTILE_HPP_