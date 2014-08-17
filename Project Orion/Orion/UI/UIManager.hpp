#ifndef _UIMANAGER_HPP_
#define _UIMANAGER_HPP_

#include <vector>
#include <memory>
#include <SFML\Graphics.hpp>
#include "Quickbar.hpp"
#include "Control.hpp"

namespace Orion
{
	namespace UI
	{
		class UIManager
		{
		public:
			UIManager();
			~UIManager();

			void Add(shared_ptr<Control>);
			void Update();
			void Draw(sf::RenderWindow&);

		private:
			vector<shared_ptr<Control>> mControlList;
		};
	}
}

#endif //_UIMANAGER_HPP_