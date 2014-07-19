#include "OrionGame.hpp"

OrionGame::OrionGame(const sf::Vector2i& resolution) : Game(resolution)
{
	// load textures
	try
	{
		ResourceManager::getInstance().Textures.load("background", "background1.jpg");
		ResourceManager::getInstance().Textures.load("planet", "planet.png");
		ResourceManager::getInstance().Textures.load("player", "player.png");
		ResourceManager::getInstance().Textures.load("enemy", "enemy.png");
		ResourceManager::getInstance().Textures.load("plasma", "plasma.png");
	}
	catch (std::runtime_error& e)
	{
		printf("Exception: %s\n", e.what());
	}

	// create the objects
	auto background = make_shared<Sprite>("background");
	background->SetPosition(sf::Vector2f(resolution.x / 2, resolution.y / 2));
	background->SetOrigin(sf::Vector2f(background->GetWidth() / 2, background->GetHeight() / 2));
	background->SetZOrder(0);

	auto planet = make_shared<Sprite>("planet");
	planet->SetPosition(sf::Vector2f(1000, 550));
	planet->SetOrigin(sf::Vector2f(planet->GetWidth() / 2, planet->GetHeight() / 2));
	planet->SetZOrder(1);

	auto enemy = make_shared<Sprite>("enemy");
	enemy->SetOrigin(sf::Vector2f(enemy->GetWidth() / 2, enemy->GetHeight() / 2));
	enemy->SetPosition(sf::Vector2f(resolution.x - 150, resolution.y / 2));
	enemy->SetRotation(-90.0f);
	enemy->SetScale(0.8f, 0.8f);
	enemy->SetZOrder(2);

	player = make_shared<Sprite>("player");
	player->SetOrigin(sf::Vector2f(player->GetWidth() / 2, player->GetHeight() / 2));
	player->SetPosition(sf::Vector2f(160, resolution.y / 2));
	player->SetRotation(90.0f);
	player->SetZOrder(3);

	auto layer = make_shared<Layer>();
	layer->AddSprite(background);
	layer->AddSprite(planet);
	layer->AddSprite(enemy);
	layer->AddSprite(player);

	battleScene = make_shared<Scene>();
	battleScene->Add(layer);
}

void OrionGame::Input(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Space)
	{
		if (!isPressed)
		{
			auto projectile = make_shared<Projectile>("plasma");
			projectile->SetOrigin(sf::Vector2f(projectile->GetWidth() / 2, projectile->GetHeight() / 2));
			projectile->SetPosition(sf::Vector2f(player->GetPosition().x + (player->GetWidth() / 2) - 50, player->GetPosition().y));
			projectile->SetRotation(player->GetRotation());
			projectile->SetScale(0.5f, 0.5f);
			projectile->SetVelocity(sf::Vector2f(1000.0f, 0.0f));
			projectile->SetZOrder(50);
			battleScene->Add(projectile);
		}
	}
}

void OrionGame::Update(sf::Time elapsedTime)
{
	battleScene->Update(elapsedTime);
}

void OrionGame::Render()
{
	mWindow.clear();
	battleScene->Draw(mWindow);
	mWindow.display();
}