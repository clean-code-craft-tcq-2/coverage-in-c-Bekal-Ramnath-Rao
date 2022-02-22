#include "typewise-alert.h"
#include <stdio.h>

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{
  Limit limit;
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  alertTarget(breachType);
}
