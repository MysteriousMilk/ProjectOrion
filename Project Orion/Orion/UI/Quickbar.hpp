#ifndef _QUICKBAR_HPP_
#define _QUICKBAR_HPP_

#include "QuickbarItem.hpp"
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

			void Add(shared_ptr<QuickbarItem>);
			void ProcessEvents(const sf::Event&);
			void Update();
			void Draw(sf::RenderWindow&);

		private:
			sf::RenderTexture mToolbarTexture;
			std::vector<shared_ptr<QuickbarItem>> mItems;
		};

		bool SortQuickbar(shared_ptr<QuickbarItem> one, shared_ptr<QuickbarItem> two);
	}
}

#endif //_QUICKBAR_HPP_