//
// Created by kieranmc on 09/11/2022.
//

#include <gtest/gtest.h>
#include "../../inc/day14/race_simulator.hpp"

TEST(RaceSimulatorTests, SimulateRace) {
  auto target = RaceSimulator();

  Reindeer reindeer;

  reindeer.str_name = "Dancer";
  reindeer.u16_speedKmSecs = 27;
  reindeer.u16_maxTravelPeriodSecs = 5;
  reindeer.u16_restPeriodSecs = 132;
  target.AddReindeer(reindeer);

  reindeer.str_name = "Cupid";
  reindeer.u16_speedKmSecs = 22;
  reindeer.u16_maxTravelPeriodSecs = 2;
  reindeer.u16_restPeriodSecs = 41;
  target.AddReindeer(reindeer);

  reindeer.str_name = "Rudolph";
  reindeer.u16_speedKmSecs = 11;
  reindeer.u16_maxTravelPeriodSecs = 5;
  reindeer.u16_restPeriodSecs = 48;
  target.AddReindeer(reindeer);

  reindeer.str_name = "Donner";
  reindeer.u16_speedKmSecs = 29;
  reindeer.u16_maxTravelPeriodSecs = 5;
  reindeer.u16_restPeriodSecs = 134;
  target.AddReindeer(reindeer);

  reindeer.str_name = "Dasher";
  reindeer.u16_speedKmSecs = 4;
  reindeer.u16_maxTravelPeriodSecs = 16;
  reindeer.u16_restPeriodSecs = 55;
  target.AddReindeer(reindeer);

  reindeer.str_name = "Blitzen";
  reindeer.u16_speedKmSecs = 14;
  reindeer.u16_maxTravelPeriodSecs = 3;
  reindeer.u16_restPeriodSecs = 38;
  target.AddReindeer(reindeer);

  reindeer.str_name = "Prancer";
  reindeer.u16_speedKmSecs = 3;
  reindeer.u16_maxTravelPeriodSecs = 21;
  reindeer.u16_restPeriodSecs = 40;
  target.AddReindeer(reindeer);

  reindeer.str_name = "Comet";
  reindeer.u16_speedKmSecs = 18;
  reindeer.u16_maxTravelPeriodSecs = 6;
  reindeer.u16_restPeriodSecs = 103;
  target.AddReindeer(reindeer);

  reindeer.str_name = "Vixen";
  reindeer.u16_speedKmSecs = 18;
  reindeer.u16_maxTravelPeriodSecs = 5;
  reindeer.u16_restPeriodSecs = 84;
  target.AddReindeer(reindeer);

  target.Race(2503);

  std::cout << "Winner: " << target.GetWinner().str_name;
  std::cout << "Distance: " << target.GetWinningDistance();
}