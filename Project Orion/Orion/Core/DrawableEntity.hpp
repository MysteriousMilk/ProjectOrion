#ifndef _DRAWABLEENTITY_HPP_
#define	_DRAWABLEENTITY_HPP_

#include <memory>
#include <SFML\Graphics.hpp>
#include "SceneNode.hpp"

using namespace std;

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
		
		virtual bool IsAlive() = 0;
		virtual int Count() = 0;
		virtual void Update(sf::Time&) = 0;
		virtual void Draw(sf::RenderWindow&) = 0;

		shared_ptr<SceneNode> Parent;

	protected:
		int mZOrder;
		bool mAlive;
	};
}

#endif //_DRAWABLEENTITY_HPP_