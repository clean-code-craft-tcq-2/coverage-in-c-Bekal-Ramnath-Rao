#pragma once

typedef struct {
  float lowerLimitforCoolingType;
  float higherLimitforCoolingType; 
}Limit;

typedef void (*CoolingType)(Limit);

void PASSIVE_COOLING(Limit);
void HI_ACTIVE_COOLING(Limit);
void MED_ACTIVE_COOLING(Limit);

typedef void (*BreachType)(const char*);

void NORMAL(const char*);
void TOO_LOW(const char*);
void TOO_HIGH(const char*);

BreachType inferBreach(double , double , double );
BreachType classifyTemperatureBreach(CoolingType , double , Limit);
void setrangeforCoolingType(float, float, Limit);

typedef void (*AlertTarget)(BreachType);

void TO_CONTROLLER(BreachType);
void TO_EMAIL(BreachType);


typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(AlertTarget, BatteryCharacter, double);
