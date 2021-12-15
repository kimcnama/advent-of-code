//
// Created by kieran McNamara on 15/12/2021.
//

#include "../../inc/day4/md5_wrapper.h"
#include <CkCrypt2.h>

void MD5Wrapper(const char *pch_message, char *pch_digest) {
  // This example assumes the Chilkat API to have been previously unlocked.
  // See Global Unlock Sample for sample code.

  uint8_t u8_nBytes = 16;

  CkCrypt2 crypt;

  // The desired output is a hexidecimal string:
  crypt.put_EncodingMode("hex");

  // Set the hash algorithm:
  crypt.put_HashAlgorithm("md5");
  const char* p_digest = crypt.hashStringENC(pch_message);

  for (uint8_t i = 0; i < u8_nBytes; ++i) {
    pch_digest[i] = p_digest[i];
  }
}

bool AdventMiner(const char* pch_message, uint8_t u8_nBytes) {

  char digest[16];
  MD5Wrapper(pch_message, digest);

  for (uint8_t i = 0; i < u8_nBytes; ++i) {
    if (digest[i] != '0') {
      return false;
    }
  } return true;
}
