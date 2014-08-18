#ifndef _QUICKBARITEM_HPP_
#define _QUICKBARITEM_HPP_

#include "../Core/ScriptEngine.hpp"
#include "Control.hpp"

namespace Orion
{
	namespace UI
	{
		class QuickbarItem : public Control
		{
		public:
			QuickbarItem(std::string, std::string);
			~QuickbarItem();

			int GetSlot();
			void SetSlot(int);

			void OnClick();

		private:
			int mSlot;
			std::string mScriptRef;
		};
	}
}

#endif // _QUICKBARITEM_HPP_