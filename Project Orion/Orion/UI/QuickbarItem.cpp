#include "QuickbarItem.hpp"

namespace Orion
{
	namespace UI
	{
		QuickbarItem::QuickbarItem(std::string textureRef, std::string scriptRef)
			: Control(textureRef)
		{
			mScriptRef = scriptRef;
			mSlot = 0;

			SetSize(sf::Vector2f(24, 24));
			SetVisible(true);
		}

		QuickbarItem::~QuickbarItem() {}

		void QuickbarItem::OnClick()
		{
			printf("Quickbar OnClick().\n");
			ScriptEngine::getInstance().Execute(mScriptRef);
		}

		int QuickbarItem::GetSlot()
		{
			return mSlot;
		}

		void QuickbarItem::SetSlot(int slot)
		{
			mSlot = slot;
		}
	}
}