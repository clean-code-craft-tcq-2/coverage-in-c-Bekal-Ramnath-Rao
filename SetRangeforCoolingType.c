#include "SetRangeforCoolingType.h"

Limit setrangeforCoolingType(float low, float high)
{
	Limit limit;
	limit.lowerLimitforCoolingType = low;
	limit.higherLimitforCoolingType = high;
	return limit;
}