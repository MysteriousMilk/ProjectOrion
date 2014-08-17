#ifndef _QUICKBAR_HPP_
#define _QUICKBAR_HPP_

#include "Control.hpp"

namespace Orion
{
	namespace UI
	{
		class Quickbar : public Control
		{
		public:
			Quickbar(int);
			~Quickbar();

			void Update();
			void Draw(sf::RenderWindow&);

		private:
			sf::RenderTexture mToolbarTexture;
		};
	}
}

#endif //_QUICKBAR_HPP_