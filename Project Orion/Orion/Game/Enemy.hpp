#ifndef _ENEMY_HPP_
#define _ENEMY_HPP_

#include "../Core/Sprite.hpp"

namespace Orion
{
	namespace Game
	{
		class Enemy : public SceneNode
		{
		public:
			Enemy(std::string);
			~Enemy();

			// primarily used for scripting
			float				GetX();
			float				GetY();

			// sprite related stuff
			bool				IsAlive();
			int					Count();
			shared_ptr<Sprite>	GetSprite();
			void				Update(sf::Time&);
			void				Draw(sf::RenderWindow&);
			void				Add(shared_ptr<SceneNode>);

		private:
			shared_ptr<Sprite> mSprite;
		};
	}
}

#endif //_ENEMY_HPP_