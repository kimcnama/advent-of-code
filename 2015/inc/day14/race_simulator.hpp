//
// Created by kieranmc on 09/11/2022.
//

#ifndef ADVENTOFCODE_RACE_SIMULATOR_HPP
#define ADVENTOFCODE_RACE_SIMULATOR_HPP

#include <iostream>
#include <vector>

struct Reindeer {
  std::string str_name;
  uint16_t u16_speedKmSecs;
  uint16_t u16_maxTravelPeriodSecs;
  uint16_t u16_restPeriodSecs;
};

class RaceSimulator {
public:
  RaceSimulator();
  ~RaceSimulator();
  void AddReindeer(const Reindeer& st_reindeer);
  void Race(const uint16_t u16_raceLen);
  void RaceBySecond(const uint16_t u16_raceLen);
  Reindeer inline GetWinner();
  uint16_t inline GetWinningDistance();

protected:
  std::vector<Reindeer> _vec_reindeers;
  Reindeer _st_winningReindeer;
  uint16_t _16_winningDistance;
};

#endif //ADVENTOFCODE_RACE_SIMULATOR_HPP
