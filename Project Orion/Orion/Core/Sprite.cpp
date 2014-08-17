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
	if (!Resources::ResourceManager::getInstance().Textures.contains(resourceid))
		Resources::ResourceManager::getInstance().Textures.load(resourceid, filename);
	mTextureRef = resourceid;

	mWidth = Resources::ResourceManager::getInstance().Textures.get(resourceid).getSize().x;
	mHeight = Resources::ResourceManager::getInstance().Textures.get(resourceid).getSize().y;

	mAngle = 0;
	mScaleFactor.x = 1;
	mScaleFactor.y = 1;
	mZOrder = 0;
	mAlive = true;

	mSpriteColor = sf::Color::White;
}

Sprite::~Sprite()
{
}

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

const sf::Vector2f& Sprite::GetOrigin()
{
	return mOrigin;
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

const sf::Vector2f& Sprite::GetScale()
{
	return mScaleFactor;
}

void Sprite::SetScale(float scalex, float scaley)
{
	mScaleFactor.x = scalex;
	mScaleFactor.y = scaley;
}

sf::Color& Sprite::GetColor()
{
	return mSpriteColor;
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

std::shared_ptr<Sprite> Sprite::Clone()
{
	auto clone = std::make_shared<Sprite>(mTextureRef);
	clone->SetPosition(mPosition);
	clone->SetVelocity(mVelocity);
	clone->SetAlive(mAlive);
	clone->SetColor(mSpriteColor);
	clone->SetOrigin(mOrigin);
	clone->SetRotation(mAngle);
	clone->SetScale(mScaleFactor.x, mScaleFactor.y);
	clone->SetZOrder(mZOrder);
	return clone;
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

void Sprite::Add(shared_ptr<SceneNode> node)
{
	return;
}

}