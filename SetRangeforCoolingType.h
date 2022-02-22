#ifndef SETRANGEFORCOOLINGTYPE_H__
#define SETRANGEFORCOOLINGTYPE_H__

typedef struct {
  double lowerLimitforCoolingType;
  double higherLimitforCoolingType; 
}Limit;

Limit setrangeforCoolingType(float, float);

#endif