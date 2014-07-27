#ifndef _QUICKBARITEM_HPP_
#define _QUICKBARITEM_HPP_

#include "Control.hpp"

class QuickbarItem : public Control
{
public:
	QuickbarItem();
	~QuickbarItem();

	void(*QuickbarItemCallback)(void);

private:
	float mCooldown;
};
#endif