#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_

#include <math.h>
#include <SFML\Graphics.hpp>
#include "SceneNode.hpp"
#include "DrawableEntity.hpp"
#include "..\Resources\ResourceManager.hpp"

namespace Orion
{
	class Sprite : public SceneNode
	{
	public:
		Sprite(std::string);
		Sprite(std::string, std::string);
		~Sprite();

		const sf::Vector2f& GetPosition();
		void SetPosition(const sf::Vector2f&);

		const sf::Vector2f& GetVelocity();
		void SetVelocity(const sf::Vector2f&);

		const sf::Vector2f& GetOrigin();
		void SetOrigin(const sf::Vector2f&);
		
		float GetRotation();
		void SetRotation(float);

		const sf::Vector2f& GetScale();
		void SetScale(float, float);

		sf::Color& GetColor();
		void SetColor(sf::Color&);

		int GetWidth();
		int GetHeight();

		bool IsAlive();
		void SetAlive(bool);

		std::shared_ptr<Sprite> Clone();

		int  Count();
		void Update(sf::Time&);
		void Draw(sf::RenderWindow&);
		void Add(shared_ptr<SceneNode>);

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
	};
}

#endif //_SPRITE_HPP_