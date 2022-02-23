#include "BreachType.h"
#include "stdio.h"

void NORMAL(const char* recepient)
{
	batteryBreachtype = normal;
	printf("To: %s\n", recepient);
    printf("Hi, the temperature is normal\n");
}

void TOO_LOW(const char* recepient)
{
	batteryBreachtype = too_low;
	printf("To: %s\n", recepient);
    printf("Hi, the temperature is too low\n");
}

void TOO_HIGH(const char* recepient)
{
	batteryBreachtype = too_high;
	printf("To: %s\n", recepient);
    printf("Hi, the temperature is too high\n");
}