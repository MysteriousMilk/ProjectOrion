#ifndef _DRAWABLEENTITY_HPP_
#define	_DRAWABLEENTITY_HPP_

#include <SFML\Graphics.hpp>

namespace Orion
{
	class DrawableEntity
	{
	public:
		int GetZOrder() { return mZOrder; }
		void SetZOrder(int z)
		{
			mZOrder = z;
		}

		virtual int Count() = 0;
		virtual void Update(sf::Time&) = 0;
		virtual void Draw(sf::RenderWindow&) = 0;

	protected:
		int mZOrder;
	};
}

#endif //_DRAWABLEENTITY_HPP_