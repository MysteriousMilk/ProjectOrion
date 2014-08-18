#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/Graphics.hpp>
#include "../Factories/WeaponFactory.hpp"

using namespace std;

namespace Orion
{
	namespace Game
	{
		class Game : private sf::NonCopyable
		{
		public:
			Game(const sf::Vector2i&);
			void					Run();

		private:
			virtual void			ProcessEvents();
			virtual void			Update(sf::Time elapsedTime);
			virtual void			Render();

			void					UpdateStatistics(sf::Time elapsedTime);
			virtual void			Input(sf::Keyboard::Key key, bool isPressed);

		protected:
			sf::RenderWindow		mWindow;

		private:
			static const sf::Time	TimePerFrame;

			sf::Font				mFont;
			sf::Text				mStatisticsText;
			sf::Time				mStatisticsUpdateTime;
			sf::Vector2i			mResolution;

			std::size_t				mStatisticsNumFrames;
		};
	}
}

#endif // _GAME_HPP_