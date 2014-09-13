#ifndef _ORIONGAME_HPP_
#define _ORIONGAME_HPP_

#include "Orion\Core\ScriptEngine.hpp"
#include "Orion\UI\UIManager.hpp"
#include "Orion\Orion.hpp"
#include "Orion\Event\EventQueue.hpp"

using namespace Orion;
using namespace Orion::Game;
using namespace Orion::UI;
using namespace Orion::Resources;

class OrionGame : public Game
{
public:
	OrionGame(const sf::Vector2i&);

	void ProcessEvents();
	void Input(sf::Keyboard::Key key, bool isPressed);
	void Update(sf::Time elapsedTime);
	void Render();

private:
	UIManager UserInterface;
	shared_ptr<Player> mPlayer;
	//shared_ptr<Sprite> player;
	shared_ptr<Scene> battleScene;

	int rocketCount;
	bool isFiring;
	float elapsed;
	float timeSinceLast;
};

#endif //_ORIONGAME_HPP_