//
// Created by kieranmc on 09/11/2022.
//

#include <map>
#include "../../inc/day14/race_simulator.hpp"

RaceSimulator::RaceSimulator() = default;

RaceSimulator::~RaceSimulator() = default;

void RaceSimulator::AddReindeer(const Reindeer& st_reindeer) {
  this->_vec_reindeers.push_back(st_reindeer);
}

void RaceSimulator::Race(const uint16_t u16_raceLen) {

  uint16_t u16_maxDistance = 0;
  uint16_t u16_currDistance;
  uint16_t u16_currSec;
  uint16_t u16_secIncrement;
  bool b_isResting;
  bool b_winningReindeerSet = false;

  for ( auto &reindeer : this->_vec_reindeers ) {
    this->_16_winningDistance = 0;
    u16_currDistance = 0;
    u16_currSec = 0;
    u16_secIncrement = 0;
    b_isResting = false;

    while (u16_currSec < u16_raceLen) {
      if (b_isResting) {
        u16_secIncrement = u16_raceLen - u16_currSec >= reindeer.u16_restPeriodSecs ? reindeer.u16_restPeriodSecs : u16_raceLen - u16_currSec;
      } else {
        u16_secIncrement = u16_raceLen - u16_currSec >= reindeer.u16_maxTravelPeriodSecs ? reindeer.u16_maxTravelPeriodSecs : u16_raceLen - u16_currSec;
      }

      u16_currDistance += u16_secIncrement * reindeer.u16_speedKmSecs * !b_isResting;
      u16_currSec += u16_secIncrement;
      b_isResting = !b_isResting;
    }
    if (!b_winningReindeerSet || u16_currDistance > u16_maxDistance) {
      b_winningReindeerSet = true;

      this->_st_winningReindeer = Reindeer();
      this->_st_winningReindeer.str_name = reindeer.str_name;
      this->_st_winningReindeer.u16_speedKmSecs = reindeer.u16_speedKmSecs;
      this->_st_winningReindeer.u16_maxTravelPeriodSecs = reindeer.u16_maxTravelPeriodSecs;
      this->_st_winningReindeer.u16_restPeriodSecs = reindeer.u16_restPeriodSecs;
      u16_maxDistance = u16_currDistance;
    }
  }
  this->_16_winningDistance = u16_maxDistance;
}

Reindeer inline RaceSimulator::GetWinner() {
  return this->_st_winningReindeer;
}

uint16_t inline RaceSimulator::GetWinningDistance() {
  return this->_16_winningDistance;
}

void RaceSimulator::RaceBySecond(const uint16_t u16_raceLen) {

  std::map<std::string, uint16_t> map_raceDistance;

  for ( auto &reindeer : this->_vec_reindeers ) {
    map_raceDistance.insert({reindeer.str_name, 0});
  }

  for (uint16_t u16_i = 0; u16_i < u16_raceLen; ++u16_i) {



  }

}
