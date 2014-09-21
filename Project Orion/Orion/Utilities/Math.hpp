#ifndef _MATH_HPP_
#define _MATH_HPP_

#define _USE_MATH_DEFINES

#include <math.h>

namespace Orion
{
	namespace Utilities
	{
		class Math
		{
		public:
			static double ToDegrees(double radians)
			{
				return radians * (180 / M_PI);
			}

			static double ToRadians(double degrees)
			{
				return degrees * (M_PI / 180);
			}
		};
	}
}

#endif // _MATH_HPP_