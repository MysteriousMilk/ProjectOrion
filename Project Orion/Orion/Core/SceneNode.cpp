#include "SceneNode.hpp"

namespace Orion
{
	bool sortNodesInScene(shared_ptr<SceneNode> first, shared_ptr<SceneNode> second)
	{
		return first->GetZOrder() < second->GetZOrder();
	}
}