#include "OrionGame.hpp"

OrionGame::OrionGame(const sf::Vector2i& resolution) : Game(resolution)
{
	// load textures
	try
	{
		// ui
		ResourceManager::getInstance().Textures.load("ToolbarLeft", "resources/ui/toolbar_left.png");
		ResourceManager::getInstance().Textures.load("ToolbarRight", "resources/ui/toolbar_right.png");
		ResourceManager::getInstance().Textures.load("ToolbarCenter", "resources/ui/toolbar_center.png");

		ResourceManager::getInstance().Textures.load("background", "resources/images/background1.jpg");
		ResourceManager::getInstance().Textures.load("planet", "resources/images/planet.png");
		ResourceManager::getInstance().Textures.load("player", "resources/images/player.png");
		ResourceManager::getInstance().Textures.load("enemy", "resources/images/enemy.png");
		ResourceManager::getInstance().Textures.load("plasma", "resources/images/projectiles/plasma.png");
		ResourceManager::getInstance().Textures.load("rocket", "resources/images/projectiles/rocket.png");
	}
	catch (std::runtime_error& e)
	{
		printf("Exception: %s\n", e.what());
	}

	// create the objects
	auto background = make_shared<Sprite>("background");
	background->SetPosition(sf::Vector2f(resolution.x / 2.0f, resolution.y / 2.0f));
	background->SetOrigin(sf::Vector2f(background->GetWidth() / 2.0f, background->GetHeight() / 2.0f));
	background->SetZOrder(0);

	auto planet = make_shared<Sprite>("planet");
	planet->SetPosition(sf::Vector2f(resolution.x / 2.0f, 650.0f));
	planet->SetOrigin(sf::Vector2f(planet->GetWidth() / 2.0f, planet->GetHeight() / 2.0f));
	planet->SetZOrder(1);

	auto enemy = make_shared<Sprite>("enemy");
	enemy->SetOrigin(sf::Vector2f(enemy->GetWidth() / 2.0f, enemy->GetHeight() / 2.0f));
	enemy->SetPosition(sf::Vector2f(resolution.x - 175.0f, resolution.y / 2.0f));
	enemy->SetRotation(-90.0f);
	enemy->SetScale(0.8f, 0.8f);
	enemy->SetZOrder(2);

	mPlayer = make_shared<Player>("player");
	mPlayer->GetSprite()->SetOrigin(sf::Vector2f(mPlayer->GetSprite()->GetWidth() / 2.0f,
												 mPlayer->GetSprite()->GetHeight() / 2.0f));
	mPlayer->GetSprite()->SetPosition(sf::Vector2f(175.0f, resolution.y / 2.0f));
	mPlayer->GetSprite()->SetRotation(90.0f);
	mPlayer->SetZOrder(3);

	auto layer = make_shared<Layer>();
	layer->Add(background);
	layer->Add(planet);
	layer->Add(enemy);
	layer->Add(mPlayer);

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

	Orion::Factories::WeaponFactory weaponFactory;
	auto weapon = weaponFactory.GetWeaponById(1);
	mPlayer->SetWeapon(weapon, WEAPON_TYPE_ROCKET);

	printf("Weapon(%d, %s, %d)\n", weapon->GetId(), weapon->GetName().c_str(), weapon->GetMinimumLevel());
	printf("\t->Projectile(%d, %s, %s, %s, %d, %lf)\n",
		weapon->GetProjectile()->GetId(),
		weapon->GetProjectile()->GetName().c_str(),
		weapon->GetProjectile()->GetFilename().c_str(),
		weapon->GetProjectile()->GetReference().c_str(),
		weapon->GetProjectile()->GetWeaponId(),
		weapon->GetProjectile()->GetSpeed());

	Orion::Engine::getInstance().RegisterPlayer(mPlayer.get());
}

void OrionGame::Input(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Space)
	{
		if (!isPressed)
		{
			//auto projectile = make_shared<Projectile>("plasma");
			//projectile->SetOrigin(sf::Vector2f(projectile->GetWidth() / 2, projectile->GetHeight() / 2));
			//projectile->SetPosition(sf::Vector2f(mPlayer->GetSprite()->GetPosition().x + (mPlayer->GetSprite()->GetWidth() / 2) - 50,
			//	mPlayer->GetSprite()->GetPosition().y));
			//projectile->SetRotation(mPlayer->GetSprite()->GetRotation());
			//projectile->SetScale(0.5f, 0.5f);
			//projectile->SetVelocity(sf::Vector2f(1000.0f, 0.0f));
			//projectile->SetColor(sf::Color(255, 255, 255, 200));
			//projectile->SetZOrder(50);
			//battleScene->Add(projectile);
			//mPlayer->FireProjectile(WEAPON_TYPE_ROCKET);
			Script.Execute("resources/scripts/orion_fire_rockets.lua");

			isFiring = true;
		}
	}
}

void OrionGame::Update(sf::Time elapsedTime)
{
	timeSinceLast = elapsedTime.asMilliseconds() - timeSinceLast;
	/*if (isFiring)
	{
		elapsed += timeSinceLast;
		if (rocketCount == 0)
		{
			auto projectile = make_shared<Projectile>("rocket");
			projectile->SetOrigin(sf::Vector2f(projectile->GetWidth() / 2.0f, projectile->GetHeight() / 2.0f));
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
				projectile->SetOrigin(sf::Vector2f(projectile->GetWidth() / 2.0f, projectile->GetHeight() / 2.0f));
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
	}*/

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