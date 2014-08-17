#include "Layer.hpp"

namespace Orion {

Layer::Layer()
{

}

Layer::~Layer()
{

}

bool Layer::IsAlive()
{
	return true;
}

int Layer::Count()
{
	return mDrawableList.size();
}

void Layer::Add(shared_ptr<SceneNode> node)
{
	node->SetParent(this);
	mDrawableList.push_back(node);

	sort(mDrawableList.begin(), mDrawableList.end(), sortNodesInScene);
}

void Layer::Update(sf::Time& deltaTime)
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

void Layer::Draw(sf::RenderWindow& window)
{
	for (auto iterator = mDrawableList.begin(); iterator != mDrawableList.end(); ++iterator)
		iterator->get()->Draw(window);
}

}