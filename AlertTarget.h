#ifndef ALERTTARGET_H__
#define ALERTTARGET_H__

#include "BreachType.h"

typedef void (*AlertTarget)(BreachType);

void TO_CONTROLLER(BreachType);
void TO_EMAIL(BreachType);

#endif