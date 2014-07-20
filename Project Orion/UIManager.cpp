#include "UIManager.hpp"

UIManager::UIManager()
{

}

UIManager::~UIManager()
{

}

void UIManager::Add(shared_ptr<Control> ctrl)
{
	mControlList.push_back(ctrl);
}

void UIManager::Update()
{
	for (auto iterator = mControlList.begin(); iterator != mControlList.end(); ++iterator)
	{
		iterator->get()->Update();
	}
}

void UIManager::Draw(sf::RenderWindow& window)
{
	for (auto iterator = mControlList.begin(); iterator != mControlList.end(); ++iterator)
	{
		iterator->get()->Draw(window);
	}
}