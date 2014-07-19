#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include <map>
#include <memory>
#include <SFML\Graphics.hpp>
#include "Layer.hpp"

using namespace std;

namespace Orion
{
	class Scene : public DrawableEntity
	{
	public:
		Scene();
		~Scene();

		int  Count();
		void Add(shared_ptr<DrawableEntity>);
		void Update(sf::Time&);
		void Draw(sf::RenderWindow&);

	private:
		vector<shared_ptr<DrawableEntity>> mDrawableList;
		int mNextId;
	};

	bool sortDrawablesInScene(shared_ptr<DrawableEntity>, shared_ptr<DrawableEntity>);
}

#endif //_SCENE_HPP_