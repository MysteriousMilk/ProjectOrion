#include "Game.hpp"

namespace Orion
{
	namespace Game
	{
		const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

		Game::Game(const sf::Vector2i& resolution)
			: mWindow(sf::VideoMode(resolution.x, resolution.y), "Project Orion", sf::Style::Close)
			, mFont()
			, mStatisticsText()
			, mStatisticsUpdateTime()
			, mStatisticsNumFrames(0)
			, mResolution(1280, 720)
		{
			mFont.loadFromFile("resources/fonts/arial.ttf");
			mStatisticsText.setFont(mFont);
			mStatisticsText.setPosition(5.f, 5.f);
			mStatisticsText.setCharacterSize(14);
			mStatisticsText.setColor(sf::Color::Yellow);
			//Orion::Engine::SetResolution(resolution);
		}

		void Game::Run()
		{
			sf::Clock clock;
			sf::Time timeSinceLastUpdate = sf::Time::Zero;

			while (mWindow.isOpen())
			{
				sf::Time elapsedTime = clock.restart();
				timeSinceLastUpdate += elapsedTime;
				while (timeSinceLastUpdate > TimePerFrame)
				{
					timeSinceLastUpdate -= TimePerFrame;

					ProcessEvents();
					Update(TimePerFrame);
				}

				UpdateStatistics(elapsedTime);
				Render();
			}
		}

		void Game::ProcessEvents()
		{

		}

		void Game::UpdateStatistics(sf::Time elapsedTime)
		{
			mStatisticsUpdateTime += elapsedTime;
			mStatisticsNumFrames += 1;

			if (mStatisticsUpdateTime >= sf::seconds(1.0f))
			{
				mStatisticsText.setString(
					"Frames / Second = " + std::to_string(mStatisticsNumFrames) + "\n" +
					"Time / Update = " + std::to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us\n");

				mStatisticsUpdateTime -= sf::seconds(1.0f);
				mStatisticsNumFrames = 0;
			}
		}

		void Game::Update(sf::Time elapsedTime)
		{

		}

		void Game::Render()
		{

		}

		void Game::Input(sf::Keyboard::Key key, bool isPressed)
		{

		}
	}
}