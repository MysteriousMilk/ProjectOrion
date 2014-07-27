#include "OrionGame.hpp"

OrionGame::OrionGame(const sf::Vector2i& resolution) : Game(resolution)
{
	// load textures
	try
	{
		// ui
		ResourceManager::getInstance().Textures.load("ToolbarLeft", "ui/toolbar_left.png");
		ResourceManager::getInstance().Textures.load("ToolbarRight", "ui/toolbar_right.png");
		ResourceManager::getInstance().Textures.load("ToolbarCenter", "ui/toolbar_center.png");

		ResourceManager::getInstance().Textures.load("background", "background1.jpg");
		ResourceManager::getInstance().Textures.load("planet", "planet.png");
		ResourceManager::getInstance().Textures.load("player", "player.png");
		ResourceManager::getInstance().Textures.load("enemy", "enemy.png");
		ResourceManager::getInstance().Textures.load("plasma", "plasma.png");
		ResourceManager::getInstance().Textures.load("rocket", "rocket.png");
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
	planet->SetPosition(sf::Vector2f(resolution.x / 2, 650));
	planet->SetOrigin(sf::Vector2f(planet->GetWidth() / 2, planet->GetHeight() / 2));
	planet->SetZOrder(1);

	auto enemy = make_shared<Sprite>("enemy");
	enemy->SetOrigin(sf::Vector2f(enemy->GetWidth() / 2, enemy->GetHeight() / 2));
	enemy->SetPosition(sf::Vector2f(resolution.x - 175, resolution.y / 2));
	enemy->SetRotation(-90.0f);
	enemy->SetScale(0.8f, 0.8f);
	enemy->SetZOrder(2);

	player = make_shared<Sprite>("player");
	player->SetOrigin(sf::Vector2f(player->GetWidth() / 2, player->GetHeight() / 2));
	player->SetPosition(sf::Vector2f(175, resolution.y / 2));
	player->SetRotation(90.0f);
	player->SetZOrder(3);

	auto layer = make_shared<Layer>();
	layer->AddSprite(background);
	layer->AddSprite(planet);
	layer->AddSprite(enemy);
	layer->AddSprite(player);

	battleScene = make_shared<Scene>();
	battleScene->Add(layer);

	auto ctrl = make_shared<Quickbar>(10);
	ctrl->SetPosition(sf::Vector2f(15, 500));
	ctrl->SetSize(sf::Vector2f(32, 32));
	ctrl->SetColor(sf::Color(102, 204, 204, 220));
	UserInterface.Add(ctrl);

	rocketCount = 0;
	isFiring = false;
	elapsed = 0.0f;
	timeSinceLast = 0.0f;
}

void OrionGame::Input(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Space)
	{
		if (!isPressed)
		{
			/*auto projectile = make_shared<Projectile>("plasma");
			projectile->SetOrigin(sf::Vector2f(projectile->GetWidth() / 2, projectile->GetHeight() / 2));
			projectile->SetPosition(sf::Vector2f(player->GetPosition().x + (player->GetWidth() / 2) - 50, player->GetPosition().y));
			projectile->SetRotation(player->GetRotation());
			projectile->SetScale(0.5f, 0.5f);
			projectile->SetVelocity(sf::Vector2f(1000.0f, 0.0f));
			projectile->SetColor(sf::Color(255, 255, 255, 200));
			projectile->SetZOrder(50);
			battleScene->Add(projectile);*/

			isFiring = true;
		}
	}
}

void OrionGame::Update(sf::Time elapsedTime)
{
	timeSinceLast = elapsedTime.asMilliseconds() - timeSinceLast;
	if (isFiring)
	{
		elapsed += timeSinceLast;
		if (rocketCount == 0)
		{
			auto projectile = make_shared<Projectile>("rocket");
			projectile->SetOrigin(sf::Vector2f(projectile->GetWidth() / 2, projectile->GetHeight() / 2));
			projectile->SetPosition(sf::Vector2f(player->GetPosition().x + (player->GetWidth() / 2) - 250, player->GetPosition().y + 8));
			projectile->SetVelocity(sf::Vector2f(100.0f, 0.0f));
			projectile->SetRotation(player->GetRotation());
			projectile->SetZOrder(50);
			battleScene->Add(projectile);

			rocketCount++;
		}
		else
		{
			if (rocketCount == 1 && elapsed > 500.0f)
			{
				auto projectile = make_shared<Projectile>("rocket");
				projectile->SetOrigin(sf::Vector2f(projectile->GetWidth() / 2, projectile->GetHeight() / 2));
				projectile->SetPosition(sf::Vector2f(player->GetPosition().x + (player->GetWidth() / 2) - 250, player->GetPosition().y + 8));
				projectile->SetVelocity(sf::Vector2f(100.0f, 0.0f));
				projectile->SetRotation(player->GetRotation());
				projectile->SetZOrder(50);
				battleScene->Add(projectile);

				rocketCount = 0;
				isFiring = false;
				elapsed = 0.0f;
			}
		}
		printf("%lf\n", elapsed);
	}

	battleScene->Update(elapsedTime);
	UserInterface.Update();
}

void OrionGame::Render()
{
	mWindow.clear();
	battleScene->Draw(mWindow);
	UserInterface.Draw(mWindow);
	mWindow.display();
}