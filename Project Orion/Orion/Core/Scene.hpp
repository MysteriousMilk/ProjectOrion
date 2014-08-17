#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include <map>
#include <memory>
#include <SFML\Graphics.hpp>
#include "Layer.hpp"

using namespace std;

namespace Orion
{
	class Scene : public SceneNode
	{
	public:
		Scene();
		~Scene();

		bool IsAlive();
		int  Count();
		void Add(shared_ptr<SceneNode>);
		void Update(sf::Time&);
		void Draw(sf::RenderWindow&);

	private:
		vector<shared_ptr<SceneNode>> mDrawableList;
		int mNextId;
	};
}

#endif //_SCENE_HPP_