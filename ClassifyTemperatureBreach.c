#include "ClassifyTemperatureBreach.h"

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
  Limit limitCoolingType;
  limitCoolingType = coolingType();
  return inferBreach(temperatureInC, limitCoolingType.lowerLimitforCoolingType, limitCoolingType.higherLimitforCoolingType);
}