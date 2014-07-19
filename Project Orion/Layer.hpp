#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include <map>
#include <memory>
#include <SFML\Graphics.hpp>
#include "Sprite.hpp"

using namespace std;

namespace Orion
{
	class Layer : public DrawableEntity
	{
	public:
		Layer();
		~Layer();

		int  Count();
		void AddSprite(shared_ptr<Sprite>);
		void Update(sf::Time&);
		void Draw(sf::RenderWindow&);

	private:
		map<int, shared_ptr<Sprite>> mSpriteList;
	};
}

#endif _LAYER_HPP_