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
		ResourceManager::getInstance().Textures.load("RocketIcon", "resources/ui/rocket_icon.png");

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
	auto background = make_shared<Orion::Sprite>("background");
	background->SetPosition(sf::Vector2f(resolution.x / 2.0f, resolution.y / 2.0f));
	background->SetOrigin(sf::Vector2f(background->GetWidth() / 2.0f, background->GetHeight() / 2.0f));
	background->SetZOrder(0);

	auto planet = make_shared<Orion::Sprite>("planet");
	planet->SetPosition(sf::Vector2f(resolution.x / 2.0f, 650.0f));
	planet->SetOrigin(sf::Vector2f(planet->GetWidth() / 2.0f, planet->GetHeight() / 2.0f));
	planet->SetZOrder(1);

	mEnemy = make_shared<Enemy>("enemy");
	mEnemy->GetSprite()->SetOrigin(sf::Vector2f(mEnemy->GetSprite()->GetWidth() / 2.0f, mEnemy->GetSprite()->GetHeight() / 2.0f));
	mEnemy->GetSprite()->SetPosition(sf::Vector2f(resolution.x - 175.0f, resolution.y / 2.0f));
	mEnemy->GetSprite()->SetRotation(-90.0f);
	mEnemy->GetSprite()->SetScale(0.8f, 0.8f);
	mEnemy->SetZOrder(2);

	mPlayer = make_shared<Player>("player");
	mPlayer->GetSprite()->SetOrigin(sf::Vector2f(mPlayer->GetSprite()->GetWidth() / 2.0f,
												 mPlayer->GetSprite()->GetHeight() / 2.0f));
	mPlayer->GetSprite()->SetPosition(sf::Vector2f(175.0f, resolution.y / 2.0f));
	mPlayer->GetSprite()->SetRotation(90.0f);
	mPlayer->SetZOrder(3);

	auto layer = make_shared<Layer>();
	layer->Add(background);
	layer->Add(planet);
	layer->Add(mEnemy);
	layer->Add(mPlayer);

	battleScene = make_shared<Scene>();
	battleScene->Add(layer);

	auto ctrl = make_shared<Quickbar>(10);
	ctrl->SetPosition(sf::Vector2f(15, 500));
	ctrl->SetColor(sf::Color(102, 204, 204, 220));
	auto qbItem = make_shared<QuickbarItem>("RocketIcon", "resources/scripts/orion_fire_rockets.lua");
	qbItem->SetSlot(0);
	ctrl->Add(qbItem);
	UserInterface.Add(ctrl);

	rocketCount = 0;
	isFiring = false;
	elapsed = 0.0f;
	timeSinceLast = 0.0f;

	// Rocket Battery 1
	Orion::Factories::WeaponFactory weaponFactory;
	auto weapon = weaponFactory.GetWeaponById(1);
	weapon->SetRelativeLocation(sf::Vector2f(0.0f, -100.0f));
	mPlayer->AddWeapon(weapon, WEAPON_TYPE_ROCKET);

	printf("Weapon(%d, %s, %d)\n", weapon->GetId(), weapon->GetName().c_str(), weapon->GetMinimumLevel());
	printf("\t->Projectile(%d, %s, %s, %s, %d, %lf)\n",
		weapon->GetProjectile()->GetId(),
		weapon->GetProjectile()->GetName().c_str(),
		weapon->GetProjectile()->GetFilename().c_str(),
		weapon->GetProjectile()->GetReference().c_str(),
		weapon->GetProjectile()->GetWeaponId(),
		weapon->GetProjectile()->GetSpeed());

	// Rocket Battery 2
	auto weapon2 = weaponFactory.GetWeaponById(1);
	weapon2->SetRelativeLocation(sf::Vector2f(0.0f, 100.0f));
	mPlayer->AddWeapon(weapon2, WEAPON_TYPE_ROCKET);

	printf("Weapon(%d, %s, %d)\n", weapon2->GetId(), weapon2->GetName().c_str(), weapon2->GetMinimumLevel());
	printf("\t->Projectile(%d, %s, %s, %s, %d, %lf)\n",
		weapon2->GetProjectile()->GetId(),
		weapon2->GetProjectile()->GetName().c_str(),
		weapon2->GetProjectile()->GetFilename().c_str(),
		weapon2->GetProjectile()->GetReference().c_str(),
		weapon2->GetProjectile()->GetWeaponId(),
		weapon2->GetProjectile()->GetSpeed());


	Orion::Engine::getInstance().RegisterPlayer(mPlayer.get());
	Orion::Engine::getInstance().RegisterEnemy(mEnemy.get());
}

void OrionGame::ProcessEvents()
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
		UserInterface.ProcessEvents(event);
	}
}

void OrionGame::Input(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Space)
	{
		if (!isPressed)
		{
			isFiring = true;
		}
	}
}

void OrionGame::Update(sf::Time elapsedTime)
{
	timeSinceLast = elapsedTime.asMilliseconds() - timeSinceLast;

	Orion::Event::EventQueue::getInstance().Update(elapsedTime);
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