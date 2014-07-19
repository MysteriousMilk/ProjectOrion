#include "Scene.hpp"

namespace Orion {

Scene::Scene()
{
	mNextId = 0;
}

Scene::~Scene() {}

int Scene::Count()
{
	int count = 0;
	for (auto iterator = mDrawableList.begin(); iterator != mDrawableList.end(); ++iterator)
		count += iterator->get()->Count();
	
	return count;
}

void Scene::Add(shared_ptr<DrawableEntity> entity)
{
	mDrawableList.push_back(entity);

	sort(mDrawableList.begin(), mDrawableList.end(), sortDrawablesInScene);

	mNextId++;
}

void Scene::Update(sf::Time& deltaTime)
{
	for (auto iterator = mDrawableList.begin(); iterator != mDrawableList.end(); ++iterator)
	{
		Sprite* sprite = dynamic_cast<Sprite*>(iterator->get());
		if (sprite != NULL)
		{
			if (!sprite->IsAlive())
			{
				mDrawableList.erase(iterator);
				break;
			}
		}
	}

	for (auto iterator = mDrawableList.begin(); iterator != mDrawableList.end(); ++iterator)
	{
		iterator->get()->Update(deltaTime);
	}
}

void Scene::Draw(sf::RenderWindow& window)
{
	for (auto iterator = mDrawableList.begin(); iterator != mDrawableList.end(); ++iterator)
	{
		iterator->get()->Draw(window);
	}
}

bool sortDrawablesInScene(shared_ptr<DrawableEntity> first, shared_ptr<DrawableEntity> second)
{
	return first->GetZOrder() < second->GetZOrder();
}

}