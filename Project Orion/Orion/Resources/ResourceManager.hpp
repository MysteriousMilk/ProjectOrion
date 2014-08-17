#ifndef _RESOURCEMANAGER_HPP_
#define _RESOURCEMANAGER_HPP_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"
#include "../Types.hpp"

namespace Orion
{
	namespace Resources
	{
		class ResourceManager
		{
		public:
			static ResourceManager& getInstance()
			{
				static ResourceManager instance;
				return instance;
			}

			ResourceHolder<sf::Texture, std::string> Textures;
			ResourceHolder<sf::Shader, Shaders::ID> Shaders;

		private:
			ResourceManager() {};
			~ResourceManager() {};

			ResourceManager(ResourceManager const&);
			void operator=(ResourceManager const&);
		};
	}
}

#endif //_RESOURCEMANAGER_HPP_

