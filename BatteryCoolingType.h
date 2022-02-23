#ifndef BATTERYCOOLINGTYPE_H__
#define BATTERYCOOLINGTYPE_H__

#include "SetRangeforCoolingType.h"

typedef Limit (*CoolingType)();

Limit PASSIVE_COOLING();
Limit HI_ACTIVE_COOLING();
Limit MED_ACTIVE_COOLING();

#endif