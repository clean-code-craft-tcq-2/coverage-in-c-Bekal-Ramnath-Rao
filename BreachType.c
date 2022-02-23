#include "BreachType.h"
#include "stdio.h"

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