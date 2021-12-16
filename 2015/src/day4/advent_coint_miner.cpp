//
// Created by kieran McNamara on 15/12/2021.
//

#include "../../inc/day4/advent_coin_miner.h"
#include "../../inc/day4/md5_wrapper.h"

AdventCoinMiner::AdventCoinMiner(const char *pch_key, uint8_t nBytesKey) {
  _u8_nBytesKey = nBytesKey;
  _pch_solution = new char[NBYTES_MD5];;
  _pch_message = new char[NBYTES_MD5];
  _u8_nBytesSolution = 0;

  for(uint8_t i = 0; i < NBYTES_MD5; ++i) {
    _pch_solution[i] = '0';

    if (i < _u8_nBytesKey) {
      _pch_message[i] = pch_key[i];
    } else {
      _pch_message[i] = '0';
    }
  }
}

char *AdventCoinMiner::GetSolution() {
  return _pch_solution;
}

char* AdventCoinMiner::GetMessage() {
  return _pch_message;
}

uint8_t AdventCoinMiner::GetSolutionNBytes() {
  return _u8_nBytesSolution;
}

AdventCoinMiner::~AdventCoinMiner() {
  free(_pch_message);
  free(_pch_solution);
}

void AdventCoinMiner::Mine(const char* pch_key, uint8_t u8_nBytes) {

}

void AdventCoinMiner::IncrementNonce() {

  bool b_incremented = false;
  uint8_t u8_i = _u8_nBytesKey;

  while (!b_incremented && u8_i < NBYTES_MD5) {

    if (_pch_message[u8_i] == DEC_VAL_9) {
      _pch_message[u8_i] = DEC_VAL_0;
    } else {
      ++_pch_message[u8_i];
      b_incremented = true;
    }

    ++u8_i;
  }
}




