//
// Created by kieran McNamara on 15/12/2021.
//

#ifndef ADVENTOFCODE_2015_INC_DAY4_ADVENT_COIN_MINER_H_
#define ADVENTOFCODE_2015_INC_DAY4_ADVENT_COIN_MINER_H_

#include <cstdint>
#include <bitset>

#define NBYTES_MD5  16
#define DEC_VAL_0   48
#define DEC_VAL_9   57

class AdventCoinMiner {
 public:
  AdventCoinMiner(const char* pch_key, uint8_t u8_nBytesKey);
  ~AdventCoinMiner();
  void Mine(const char* pch_key, uint8_t u8_nBytes);
  uint8_t GetSolutionNBytes();
  char* GetSolution();
  char* GetMessage();
  void IncrementNonce();

 protected:
  char* _pch_message;
  char* _pch_solution;
  uint8_t _u8_nBytesKey;
  uint8_t _u8_nBytesSolution;
};

#endif //ADVENTOFCODE_2015_INC_DAY4_ADVENT_COIN_MINER_H_
