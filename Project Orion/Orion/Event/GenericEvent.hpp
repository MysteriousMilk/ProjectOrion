#ifndef _GENERICEVENT_HPP_
#define _GENERICEVENT_HPP_

namespace Orion
{
	namespace Event
	{
		class GenericEvent
		{
		public:
			virtual float GetTriggerTimeSec()
			{
				return mTriggerTimeSec;
			}
			virtual void Execute() = 0;

		protected:
			float mTriggerTimeSec;
		};
	}
}

#endif //_GENERICEVENT_HPP_