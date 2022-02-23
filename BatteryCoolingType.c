#include "BatteryCoolingType.h"
#include "SetRangeforCoolingType.h"

Limit PASSIVE_COOLING()
{
	return setrangeforCoolingType(0,35);
}

Limit HI_ACTIVE_COOLING()
{
	return setrangeforCoolingType(0,45);
}

Limit MED_ACTIVE_COOLING()
{
	return setrangeforCoolingType(0,40);
}