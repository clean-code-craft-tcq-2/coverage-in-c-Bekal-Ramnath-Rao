#ifndef BREACHTYPE_H__
#define BREACHTYPE_H__

typedef void (*BreachType)(const char*);

void NORMAL(const char*);
void TOO_LOW(const char*);
void TOO_HIGH(const char*);

typedef enum 
{
	normal,
	too_low,
	too_high
}BatteryBreachType;

BatteryBreachType batteryBreachtype;

#endif