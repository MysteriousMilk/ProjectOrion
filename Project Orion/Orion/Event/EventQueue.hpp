#ifndef _EVENTQUEUE_HPP_
#define _EVENTQUEUE_HPP_

#include <memory>
#include <queue>
#include <SFML/System.hpp>
#include "GenericEvent.hpp"

using namespace std;

namespace Orion
{
	namespace Event
	{
		class EventQueue
		{
		public:
			static EventQueue& getInstance()
			{
				static EventQueue instance;
				return instance;
			}

			float GetElapsed();
			void Add(shared_ptr<GenericEvent>);
			void Update(sf::Time&);

		private:
			EventQueue();
			~EventQueue() {};

			EventQueue(EventQueue const&);
			void operator=(EventQueue const&);

			queue<shared_ptr<GenericEvent>> mEventQueue;
			float							mElapsed;
		};
	}
}

#endif //_EVENTQUEUE_HPP_