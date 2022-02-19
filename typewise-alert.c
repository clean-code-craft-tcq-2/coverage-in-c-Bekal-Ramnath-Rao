#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

Limit setrangeforCoolingType(float low, float high)
{
	Limit limit;
	limit.lowerLimitforCoolingType = low;
	limit.higherLimitforCoolingType = high;
	return limit;
}

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

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
  Limit limitCoolingType;
  limitCoolingType = coolingType();
  return inferBreach(temperatureInC, limitCoolingType.lowerLimitforCoolingType, limitCoolingType.higherLimitforCoolingType);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  alertTarget(breachType);
}

void TO_CONTROLLER(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, *breachType);
}

void TO_EMAIL(BreachType breachType)
{
  const char* recepient = "a.b@c.com";
  breachType(recepient);
}

void NORMAL(const char* recepient)
{
	printf("To: %s\n", recepient);
    printf("Hi, the temperature is normal\n");
}

void TOO_LOW(const char* recepient)
{
	printf("To: %s\n", recepient);
    printf("Hi, the temperature is too low\n");
}

void TOO_HIGH(const char* recepient)
{
	printf("To: %s\n", recepient);
    printf("Hi, the temperature is too high\n");
}
