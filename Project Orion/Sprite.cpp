#include "Sprite.hpp"

namespace Orion {

Sprite::Sprite(std::string textureResource)
{
	mTextureRef = textureResource;

	mWidth = Resources::ResourceManager::getInstance().Textures.get(textureResource).getSize().x;
	mHeight = Resources::ResourceManager::getInstance().Textures.get(textureResource).getSize().y;

	mAngle = 0;
	mScaleFactor.x = 1;
	mScaleFactor.y = 1;
	mZOrder = 0;
	mAlive = true;

	mSpriteColor = sf::Color::White;
}

Sprite::Sprite(std::string filename, std::string resourceid)
{
	//Resources::ResourceManager::getInstance().Textures.load(resourceid, filename);

	//sf::Texture texture = Resources::ResourceManager::getInstance().Textures.get(resourceid);
	//mSprite.setTexture(texture, true);
	//mSprite.setPosition(0, 0);
	//mSprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
}

Sprite::~Sprite() {}

const sf::Vector2f& Sprite::GetPosition()
{
	return mPosition;
}

void Sprite::SetPosition(const sf::Vector2f& pos)
{
	mPosition.x = pos.x;
	mPosition.y = pos.y;
}

const sf::Vector2f& Sprite::GetVelocity()
{
	return mVelocity;
}

void Sprite::SetVelocity(const sf::Vector2f& vel)
{
	mVelocity.x = vel.x;
	mVelocity.y = vel.y;
}

void Sprite::SetOrigin(const sf::Vector2f& origin)
{
	mOrigin.x = origin.x;
	mOrigin.y = origin.y;
}

float Sprite::GetRotation()
{
	return mAngle;
}

void Sprite::SetRotation(float angle)
{
	mAngle = angle;
}

void Sprite::SetScale(float scalex, float scaley)
{
	mScaleFactor.x = scalex;
	mScaleFactor.y = scaley;
}

void Sprite::SetColor(sf::Color& color)
{
	mSpriteColor = color;
}

int Sprite::GetWidth()
{
	return mWidth;
}

int Sprite::GetHeight()
{
	return mHeight;
}

int Sprite::Count()
{
	return 1;
}

void Sprite::SetAlive(bool isAlive)
{
	mAlive = isAlive;
}

bool Sprite::IsAlive()
{
	return mAlive;
}

void Sprite::Update(sf::Time& deltaTime)
{
	mPosition.x += mVelocity.x * deltaTime.asSeconds();
	mPosition.y += mVelocity.y * deltaTime.asSeconds();
}

void Sprite::Draw(sf::RenderWindow& window)
{
	sf::Sprite sprite(Resources::ResourceManager::getInstance().Textures.get(mTextureRef));
	sprite.setPosition(mPosition);
	sprite.setOrigin(mOrigin);
	sprite.setRotation(mAngle);
	sprite.setScale(mScaleFactor.x, mScaleFactor.y);
	sprite.setColor(mSpriteColor);
	window.draw(sprite);
}

}