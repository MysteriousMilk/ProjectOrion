#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include <map>
#include <memory>
#include <SFML\Graphics.hpp>
#include "Sprite.hpp"

using namespace std;

namespace Orion
{
	class Layer : public SceneNode
	{
	public:
		Layer();
		~Layer();

		bool IsAlive();
		int  Count();
		void Add(shared_ptr<SceneNode>);
		void Update(sf::Time&);
		void Draw(sf::RenderWindow&);

	private:
		vector<shared_ptr<SceneNode>> mDrawableList;
	};
}

#endif _LAYER_HPP_