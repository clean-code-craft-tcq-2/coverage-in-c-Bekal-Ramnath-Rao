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

void setrangeforCoolingType(float low, float high, Limit limit)
{
	limit.lowerLimitforCoolingType = low;
	limit.higherLimitforCoolingType = high;
}

void PASSIVE_COOLING(Limit limit)
{
	setrangeforCoolingType(0,35,limit);
}

void HI_ACTIVE_COOLING(Limit limit)
{
	setrangeforCoolingType(0,45,limit);
}

void MED_ACTIVE_COOLING(Limit limit)
{
	setrangeforCoolingType(0,40,limit);
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC, Limit limit) 
{
  coolingType(limit);
  return inferBreach(temperatureInC, limit.lowerLimitforCoolingType, limit.higherLimitforCoolingType);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{
  Limit limit;
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC, limit);
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
