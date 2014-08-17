#ifndef _SCENENODE_HPP_
#define _SCENENODE_HPP_

#include <SFML\Graphics.hpp>
#include <memory>
using namespace std;

namespace Orion
{
	class SceneNode
	{
	public:
		SceneNode* GetParent()
		{
			return mParent;
		}

		void SetParent(SceneNode* parent)
		{
			mParent = parent;
		}

		int GetZOrder() { return mZOrder; }
		void SetZOrder(int z)
		{
			mZOrder = z;
		}

		virtual bool IsAlive() = 0;
		virtual int Count() = 0;
		virtual void Update(sf::Time&) = 0;
		virtual void Draw(sf::RenderWindow&) = 0;
		virtual void Add(shared_ptr<SceneNode>) = 0;

	protected:
		SceneNode* mParent;
		int mZOrder;
		bool mAlive;
	};

	bool sortNodesInScene(shared_ptr<SceneNode>, shared_ptr<SceneNode>);
}

#endif //_SCENENODE_HPP_