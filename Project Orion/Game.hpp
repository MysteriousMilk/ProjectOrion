#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/Graphics.hpp>
#include "Orion.hpp"

using namespace std;

namespace Orion
{
	class Game : private sf::NonCopyable
	{
	public:
		Game(const sf::Vector2i&);
		void					Run();


	private:
		void					ProcessEvents();
		virtual void			Update(sf::Time elapsedTime) = 0;
		virtual void			Render() = 0;

		void					UpdateStatistics(sf::Time elapsedTime);
		virtual void			Input(sf::Keyboard::Key key, bool isPressed) = 0;

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

#endif // _GAME_HPP_