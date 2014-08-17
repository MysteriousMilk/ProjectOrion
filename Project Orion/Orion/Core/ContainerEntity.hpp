#ifndef _CONTAINERENTITY_HPP_
#define _CONTAINERENTITY_HPP_

#include <memory>
#include "DrawableEntity.hpp"

using namespace std;

namespace Orion
{
	class ContainerEntity
	{
	public:
		virtual void Add(shared_ptr<DrawableEntity>) = 0;
	};
}

#endif //_CONTAINERENTITY_HPP_