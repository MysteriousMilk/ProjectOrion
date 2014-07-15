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
#include "Orion.hpp"

using namespace Orion::Resources;

int main()
{
	Game game;
	game.Run();

	return 0;
}