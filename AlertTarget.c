#include "AlertTarget.h"
#include <stdio.h>

void TO_CONTROLLER(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, batteryBreachtype);
}

void TO_EMAIL(BreachType breachType)
{
  const char* recepient = "a.b@c.com";
  breachType(recepient);
}