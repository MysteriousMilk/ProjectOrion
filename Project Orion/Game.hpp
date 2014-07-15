#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/Graphics.hpp>

class Game : private sf::NonCopyable
{
public:
	Game();
	void					Run();


private:
	void					ProcessEvents();
	void					Update(sf::Time elapsedTime);
	void					Render();

	void					UpdateStatistics(sf::Time elapsedTime);
	void					Input(sf::Keyboard::Key key, bool isPressed);

private:
	static const sf::Time	TimePerFrame;

	sf::RenderWindow		mWindow;
	sf::Font				mFont;
	sf::Text				mStatisticsText;
	sf::Time				mStatisticsUpdateTime;
	sf::Vector2i			mResolution;
	sf::Sprite				background;
	sf::Sprite				planet;
	sf::Sprite				enemy;
	sf::Sprite				player;

	std::size_t				mStatisticsNumFrames;
	bool					mIsMovingUp;
	bool					mIsMovingDown;
	bool					mIsMovingRight;
	bool					mIsMovingLeft;
};

#endif // _GAME_HPP_