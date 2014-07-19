#include "Layer.hpp"

namespace Orion {

Layer::Layer()
{

}

Layer::~Layer()
{

}

int Layer::Count()
{
	return mSpriteList.size();
}

void Layer::AddSprite(shared_ptr<Sprite> sprite)
{
	mSpriteList.insert(pair<int, shared_ptr<Sprite>>(sprite->GetZOrder(), sprite));
}

void Layer::Update(sf::Time& deltaTime)
{
	for (auto iterator = mSpriteList.begin(); iterator != mSpriteList.end(); ++iterator)
	{
		if (iterator->second->IsAlive())
			iterator->second->Update(deltaTime);
		else
			mSpriteList.erase(iterator);
	}
}

void Layer::Draw(sf::RenderWindow& window)
{
	for (auto iterator = mSpriteList.begin(); iterator != mSpriteList.end(); ++iterator)
	{
		iterator->second->Draw(window);
	}
}

}