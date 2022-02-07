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
  void Mine(uint8_t u8_nLeading0s);
  char* GetSolution();
  char* GetMessage();
  void IncrementNonce();

 protected:
  char* _pch_message;
  char* _pch_solution;
  char* _pch_digest;
  uint8_t _u8_nBytesKey;
  bool _b_exhaustedSearch;
  uint32_t _u32_nonce;
  char* _pch_nonce;
  uint8_t _u8_nonceLen;
};

#endif //ADVENTOFCODE_2015_INC_DAY4_ADVENT_COIN_MINER_H_
