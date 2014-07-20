#include "Control.hpp"

Control::Control()
{
	mControlRect.top = 0;
	mControlRect.left = 0;
	mControlRect.width = 0;
	mControlRect.height = 0;

	mVisible = false;
	mColor = sf::Color::White;
	mTextureRef = "";
	mParent = nullptr;
}

Control::Control(string textureRef)
{
	mControlRect.top = 0;
	mControlRect.left = 0;
	mControlRect.width = 0;
	mControlRect.height = 0;

	mVisible = false;
	mColor = sf::Color::White;
	mTextureRef = textureRef;
	mParent = nullptr;
}

Control::~Control() {}

bool Control::IsVisible()
{
	return mVisible;
}

void Control::SetVisible(bool isVisible)
{
	mVisible = isVisible;
}

int Control::GetAlpha()
{
	return mColor.a;
}

void Control::SetAlpha(int alpha)
{
	mColor.a = alpha;
}

void Control::SetColor(const sf::Color& color)
{
	mColor = color;
}

void Control::SetPosition(const sf::Vector2f& position)
{
	mControlRect.top = position.y;
	mControlRect.left = position.x;
}

void Control::SetSize(const sf::Vector2f& size)
{
	mControlRect.width = size.x;
	mControlRect.height = size.y;
}

shared_ptr<Control> Control::GetParent()
{
	return mParent;
}

void Control::SetParent(shared_ptr<Control> parent)
{
	mParent = parent;
}

void Control::Update()
{

}

void Control::Draw(sf::RenderWindow& window)
{
	if (!mTextureRef.empty())
	{
		sf::RectangleShape drawRect;
		drawRect.setSize(sf::Vector2f(mControlRect.width, mControlRect.height));
		drawRect.setPosition(sf::Vector2f(mControlRect.left, mControlRect.top));
		drawRect.setTexture(&ResourceManager::getInstance().Textures.get(mTextureRef));
		drawRect.setFillColor(mColor);
		window.draw(drawRect);
	}
}