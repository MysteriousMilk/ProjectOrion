#ifndef _QUICKBARITEM_HPP_
#define _QUICKBARITEM_HPP_

#include "Control.hpp"

namespace Orion
{
	namespace UI
	{
		class QuickbarItem : public Control
		{
		public:
			QuickbarItem();
			~QuickbarItem();

			void(*QuickbarItemCallback)(void);

		private:
			float mCooldown;
		};
	}
}

#endif // _QUICKBARITEM_HPP_