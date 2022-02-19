#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(19, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(20, 20, 30) == NORMAL);
  REQUIRE(inferBreach(21, 20, 30) == NORMAL);
  REQUIRE(inferBreach(25, 20, 30) == NORMAL);
  REQUIRE(inferBreach(29, 20, 30) == NORMAL);
  REQUIRE(inferBreach(30, 20, 30) == NORMAL);
  REQUIRE(inferBreach(31, 20, 30) == TOO_HIGH);
  REQUIRE(inferBreach(40, 20, 30) == TOO_HIGH);
}

TEST_CASE("To test the set limit") {
  setrangeforCoolingType(20,30);
}

TEST_CASE("Classify Temperature Breach") {
  REQUIRE((classifyTemperatureBreach(HI_ACTIVE_COOLING,20) == NORMAL));
  REQUIRE((classifyTemperatureBreach(PASSIVE_COOLING,20) == NORMAL));
  REQUIRE((classifyTemperatureBreach(MED_ACTIVE_COOLING,20) == NORMAL));
  
  REQUIRE((classifyTemperatureBreach(HI_ACTIVE_COOLING,-10) == TOO_LOW));
  REQUIRE((classifyTemperatureBreach(PASSIVE_COOLING,-10) == TOO_LOW));
  REQUIRE((classifyTemperatureBreach(MED_ACTIVE_COOLING,-10) == TOO_LOW));
  
  REQUIRE((classifyTemperatureBreach(HI_ACTIVE_COOLING,50) == TOO_HIGH));
  REQUIRE((classifyTemperatureBreach(PASSIVE_COOLING,40) == TOO_HIGH));
  REQUIRE((classifyTemperatureBreach(MED_ACTIVE_COOLING,45) == TOO_HIGH));
}

TEST_CASE("checkAndAlert") {
  BatteryCharacter batteryCharacter;
	batteryCharacter.coolingType = HI_ACTIVE_COOLING;
  checkAndAlert(TO_EMAIL,batteryCharacter,40);
  checkAndAlert(TO_EMAIL,batteryCharacter,50);
  checkAndAlert(TO_EMAIL,batteryCharacter,-10);
  checkAndAlert(TO_EMAIL,batteryCharacter,10);
  checkAndAlert(TO_CONTROLLER,batteryCharacter,40);
  checkAndAlert(TO_CONTROLLER,batteryCharacter,50);
  checkAndAlert(TO_CONTROLLER,batteryCharacter,-10);
  checkAndAlert(TO_CONTROLLER,batteryCharacter,10);
}
