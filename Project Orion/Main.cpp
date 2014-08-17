#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "OrionGame.hpp"

int main()
{
	auto game = make_shared<OrionGame>(sf::Vector2i(1280, 720));
	
	// regiester the game with Orion
	Orion::Engine::getInstance().RegisterGame(game);

	// start the main game loop
	game->Run();

	return 0;
}