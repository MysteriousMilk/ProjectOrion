#ifndef _ORIONGAME_HPP_
#define _ORIONGAME_HPP_

#include "Game.hpp"

using namespace Orion;
using namespace Orion::Resources;

class OrionGame : public Game
{
public:
	OrionGame(const sf::Vector2i&);

	void Input(sf::Keyboard::Key key, bool isPressed);
	void Update(sf::Time elapsedTime);
	void Render();

private:
	shared_ptr<Sprite> player;
	shared_ptr<Scene> battleScene;
};

#endif //_ORIONGAME_HPP_