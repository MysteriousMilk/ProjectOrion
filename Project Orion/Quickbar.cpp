#include "Quickbar.hpp"

Quickbar::Quickbar(int slots)
{
	sf::RectangleShape drawRect;
	drawRect.setSize(sf::Vector2f(32, 32));

	mToolbarTexture.create(slots * 32, 32);
	mToolbarTexture.clear(sf::Color::Transparent);
	
	drawRect.setPosition(sf::Vector2f(0, 0));
	drawRect.setTexture(&ResourceManager::getInstance().Textures.get("ToolbarLeft"));
	mToolbarTexture.draw(drawRect);

	for (int i = 1; i < slots - 1; i++)
	{
		drawRect.setPosition(sf::Vector2f(i*32, 0));
		drawRect.setTexture(&ResourceManager::getInstance().Textures.get("ToolbarCenter"));
		mToolbarTexture.draw(drawRect);
	}

	drawRect.setPosition(sf::Vector2f((slots - 1) * 32, 0));
	drawRect.setTexture(&ResourceManager::getInstance().Textures.get("ToolbarRight"));
	mToolbarTexture.draw(drawRect);

	mToolbarTexture.display();
}

Quickbar::~Quickbar()
{

}

void Quickbar::Update()
{

}

void Quickbar::Draw(sf::RenderWindow& window)
{
	sf::RectangleShape drawRect;
	drawRect.setSize(static_cast<sf::Vector2f>(mToolbarTexture.getSize()));
	drawRect.setPosition(sf::Vector2f(mControlRect.left, mControlRect.top));
	drawRect.setTexture(&mToolbarTexture.getTexture());
	drawRect.setFillColor(mColor);
	window.draw(drawRect);
}