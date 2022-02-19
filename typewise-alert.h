#pragma once

typedef struct {
  double lowerLimitforCoolingType;
  double higherLimitforCoolingType; 
}Limit;

typedef Limit (*CoolingType)();

Limit PASSIVE_COOLING();
Limit HI_ACTIVE_COOLING();
Limit MED_ACTIVE_COOLING();

typedef void (*BreachType)(const char*);

void NORMAL(const char*);
void TOO_LOW(const char*);
void TOO_HIGH(const char*);

BreachType inferBreach(double , double , double );
BreachType classifyTemperatureBreach(CoolingType , double);
Limit setrangeforCoolingType(float, float);

typedef void (*AlertTarget)(BreachType);

void TO_CONTROLLER(BreachType);
void TO_EMAIL(BreachType);


typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(AlertTarget, BatteryCharacter, double);
