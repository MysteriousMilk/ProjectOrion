#include "Game.hpp"
#include "ResourceManager.hpp"

using namespace Orion::Resources;

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
: mWindow(sf::VideoMode(1280, 720), "Project Orion", sf::Style::Close)
, mFont()
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
, mIsMovingUp(false)
, mIsMovingDown(false)
, mIsMovingRight(false)
, mIsMovingLeft(false)
, mResolution(1280, 720)
{
	try
	{
		ResourceManager::getInstance().Textures.load("background", "background1.jpg");
		ResourceManager::getInstance().Textures.load("planet", "planet.png");
		ResourceManager::getInstance().Textures.load("player", "player.png");
		ResourceManager::getInstance().Textures.load("enemy", "enemy.png");
	}
	catch (std::runtime_error& e)
	{
		printf("Exception: %s\n", e.what());
	}

	background.setTexture(ResourceManager::getInstance().Textures.get("background"));
	background.setOrigin(background.getTextureRect().width / 2, background.getTextureRect().height / 2);
	background.setPosition(mResolution.x / 2, mResolution.y / 2);

	planet.setTexture(ResourceManager::getInstance().Textures.get("planet"));
	planet.setOrigin(planet.getTextureRect().width / 2, planet.getTextureRect().height / 2);
	planet.setPosition(1000, 550);

	enemy.setTexture(ResourceManager::getInstance().Textures.get("enemy"));
	enemy.setOrigin(enemy.getTextureRect().width / 2, enemy.getTextureRect().height / 2);
	enemy.setPosition(mResolution.x - 150, mResolution.y / 2);
	enemy.setRotation(-90.0f);
	enemy.setScale(0.5f, 0.5f);

	mFont.loadFromFile("arial.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(12);
	mStatisticsText.setColor(sf::Color::Yellow);
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
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			Input(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			Input(event.key.code, false);
			break;

		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::Update(sf::Time elapsedTime)
{

}

void Game::Render()
{
	mWindow.clear();
	mWindow.draw(background);
	mWindow.draw(planet);
	mWindow.draw(enemy);
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void Game::UpdateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + std::to_string(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + std::to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

void Game::Input(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}