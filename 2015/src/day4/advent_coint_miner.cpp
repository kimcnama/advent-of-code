//
// Created by kieran McNamara on 15/12/2021.
//

#include "../../inc/day4/advent_coin_miner.h"
#include "../../inc/day4/md5_wrapper.h"

AdventCoinMiner::AdventCoinMiner(const char *pch_key, uint8_t nBytesKey) {
  _u8_nBytesKey = nBytesKey;
  _u32_nonce = 0;
  _u8_nonceLen = NBYTES_MD5 - _u8_nBytesKey;
  _pch_nonce = new char[_u8_nonceLen];

  _pch_solution = new char[NBYTES_MD5];
  _pch_message = new char[NBYTES_MD5];
  _pch_digest = new char[NBYTES_MD5];
  _b_exhaustedSearch = false;

  for (uint8_t i = 0; i < nBytesKey && i < NBYTES_MD5; ++i) {
    _pch_message[i] = pch_key[i];
  }

  if (nBytesKey < NBYTES_MD5) {
    _pch_message[_u8_nBytesKey] = '\0';
  }

  _pch_solution[0] = '\0';
  _pch_digest[0] = '\0';
}

char *AdventCoinMiner::GetSolution() {
  return _pch_solution;
}

char* AdventCoinMiner::GetMessage() {
  return _pch_message;
}

AdventCoinMiner::~AdventCoinMiner() {
  free(_pch_message);
  free(_pch_solution);
  free(_pch_digest);
}

void AdventCoinMiner::Mine(uint8_t u8_nLeading0s) {

  bool b_solFound = false;
  _b_exhaustedSearch = false;

  do {

    b_solFound = AdventMiner(_pch_message, u8_nLeading0s);

    if (b_solFound) {
      for(uint8_t i = 0; i < NBYTES_MD5; ++i) {
        _pch_solution[i] = _pch_message[i];
      }
    } else {
      this->IncrementNonce();
    }

  } while (!b_solFound && !_b_exhaustedSearch);

}

void AdventCoinMiner::IncrementNonce() {

  ++_u32_nonce;
  std::string str_nonceString = std::to_string(_u32_nonce);

  for (uint8_t u8_i = 0; u8_i < NBYTES_MD5 - _u8_nBytesKey && u8_i < str_nonceString.size(); ++u8_i) {
    _pch_message[_u8_nBytesKey + u8_i] = str_nonceString.at(u8_i);
  }

  if (_u8_nBytesKey + str_nonceString.size() < NBYTES_MD5) {
    _pch_message[_u8_nBytesKey + str_nonceString.size()] = '\0';
  }
}




