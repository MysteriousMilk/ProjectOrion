#include "Enemy.hpp"

namespace Orion
{
	namespace Game
	{
		Enemy::Enemy(std::string ref)
		{
			mSprite = make_shared<Sprite>(ref);
		}

		Enemy::~Enemy() {}

		float Enemy::GetX()
		{
			return mSprite->GetPosition().x;
		}

		float Enemy::GetY()
		{
			return mSprite->GetPosition().y;
		}

		bool Enemy::IsAlive()
		{
			return mSprite->IsAlive();
		}

		int Enemy::Count()
		{
			return 1;
		}

		void Enemy::Update(sf::Time& deltaTime)
		{
			mSprite->Update(deltaTime);
		}

		void Enemy::Draw(sf::RenderWindow& window)
		{
			mSprite->Draw(window);
		}

		shared_ptr<Sprite> Enemy::GetSprite()
		{
			return mSprite;
		}

		void Enemy::Add(shared_ptr<SceneNode> node)
		{
			return;
		}
	}
}