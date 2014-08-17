#include "ScriptingDefs.hpp"

Player GetPlayer()
{
	return *Orion::Engine::getInstance().GetPlayer();
}