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
  Limit limit;
  setrangeforCoolingType(20,30,limit);
}

TEST_CASE("Classify Temperature Breach") {
  REQUIRE((classifyTemperatureBreach(HI_ACTIVE_COOLING,20,limit) == TOO_LOW));
  REQUIRE((classifyTemperatureBreach(PASSIVE_COOLING,20,limit) == NORMAL));
  REQUIRE((classifyTemperatureBreach(MED_ACTIVE_COOLING,20,limit) == NORMAL));
}
