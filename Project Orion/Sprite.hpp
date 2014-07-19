#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_

#include <SFML\Graphics.hpp>
#include "DrawableEntity.hpp"
#include "ResourceManager.hpp"

namespace Orion
{
	class Sprite : public DrawableEntity
	{
	public:
		Sprite(std::string);
		Sprite(std::string, std::string);
		~Sprite();

		const sf::Vector2f& GetPosition();
		void SetPosition(const sf::Vector2f&);

		const sf::Vector2f& GetVelocity();
		void SetVelocity(const sf::Vector2f&);

		void SetOrigin(const sf::Vector2f&);
		
		float GetRotation();
		void SetRotation(float);

		void SetScale(float, float);
		void SetColor(sf::Color&);

		int GetWidth();
		int GetHeight();

		bool IsAlive();
		void SetAlive(bool);

		int  Count();
		void Update(sf::Time&);
		void Draw(sf::RenderWindow&);

	private:
		sf::Vector2f mPosition;
		sf::Vector2f mVelocity;
		sf::Vector2f mOrigin;
		std::string mTextureRef;

		sf::Color mSpriteColor;

		float mAngle;
		sf::Vector2f mScaleFactor;

		int mWidth;
		int mHeight;

		bool mAlive;
	};
}

#endif //_SPRITE_HPP_