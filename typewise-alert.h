#ifndef TYPEWISEALERT_H__
#define TYPEWISEALERT_H__

#include "BatteryCoolingType.h"
#include "SetRangeforCoolingType.h"
#include "BreachType.h"
#include "ClassifyTemperatureBreach.h"
#include "AlertTarget.h"

typedef struct {
  CoolingType coolingType;
  AlertTarget alertTarget;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(AlertTarget, BatteryCharacter, double);

#endif
