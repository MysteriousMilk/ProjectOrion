#include "EventQueue.hpp"

namespace Orion
{
	namespace Event
	{
		EventQueue::EventQueue()
		{
			mElapsed = 0.0f;
		}

		float EventQueue::GetElapsed()
		{
			return mElapsed;
		}

		void EventQueue::Add(shared_ptr<GenericEvent> gameEvent)
		{
			mEventQueue.push(gameEvent);
			printf("Added Event (Execute Time: %lf) - Queue Size: %d\n", gameEvent->GetTriggerTimeSec(), mEventQueue.size());
		}

		void EventQueue::Update(sf::Time& deltaTime)
		{
			mElapsed += deltaTime.asSeconds();

			if (!mEventQueue.empty())
			{
				while (mEventQueue.front()->GetTriggerTimeSec() < mElapsed)
				{
					mEventQueue.front()->Execute();
					mEventQueue.pop();

					if (mEventQueue.empty())
						break;
				}
			}
		}
	}
}