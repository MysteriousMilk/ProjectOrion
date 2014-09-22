#include "ScriptingDefs.hpp"

Player GetPlayer()
{
	return *Orion::Engine::getInstance().GetPlayer();
}

Enemy GetEnemy()
{
	return *Orion::Engine::getInstance().GetEnemy();
}