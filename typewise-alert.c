#include "typewise-alert.h"
#include <stdio.h>

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{
  Limit limit;
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  alertTarget(breachType);
}

int main()
{
	BatteryCharacter batteryCharacter;
	batteryCharacter.coolingType = HI_ACTIVE_COOLING;
	batteryCharacter.alertTarget = TO_EMAIL;
	checkAndAlert(TO_EMAIL,batteryCharacter,50);
}
