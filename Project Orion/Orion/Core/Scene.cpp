#include "Scene.hpp"

namespace Orion {

Scene::Scene()
{
	mNextId = 0;
}

Scene::~Scene() {}

bool Scene::IsAlive()
{
	return true;
}

int Scene::Count()
{
	int count = 0;
	for (auto iterator = mDrawableList.begin(); iterator != mDrawableList.end(); ++iterator)
		count += iterator->get()->Count();
	
	return count;
}

void Scene::Add(shared_ptr<SceneNode> node)
{
	node->SetParent(this);
	mDrawableList.push_back(node);
	
	sort(mDrawableList.begin(), mDrawableList.end(), sortNodesInScene);

	mNextId++;
}

void Scene::Update(sf::Time& deltaTime)
{
	for (auto iterator = mDrawableList.begin(); iterator != mDrawableList.end(); ++iterator)
	{
		if (!iterator->get()->IsAlive())
		{
			mDrawableList.erase(iterator);
			break;
		}
	}

	for (auto iterator = mDrawableList.begin(); iterator != mDrawableList.end(); ++iterator)
		iterator->get()->Update(deltaTime);
}

void Scene::Draw(sf::RenderWindow& window)
{
	for (auto iterator = mDrawableList.begin(); iterator != mDrawableList.end(); ++iterator)
	{
		iterator->get()->Draw(window);
	}
}

}