#include "crc64_support.hpp"
#include <iostream>

using namespace std;

/**
 * @brief simplest crc64 c++ implementation
 * @author tongjunhui@live.cn
 * @ref https://gist.github.com/timepp
 *
 */

void crc64::generate_table(uint64_t (&table)[256]) {
  for (int i = 0; i < 256; ++i) {
    uint64_t crc = i;
    for (uint8_t j = 0; j < 8; ++j) {
      if (crc & 1) {
        crc >>= 1;
        crc ^= initial;
      } else {
        crc >>= 1;
      }
    }
    table[i] = crc;
  }
}

uint64_t crc64::update(uint64_t (&table)[256], uint64_t /*initial*/,
                       const uint8_t *buf, size_t len) {
  uint64_t crc = 0;
  for (size_t i = 0; i < len; ++i) {
    uint8_t index = buf[i] ^ crc;
    uint64_t lookup = table[index];
    crc >>= 8;
    crc ^= lookup;
  }
  return crc;
}

uint64_t crc64::table[256];
uint64_t crc64::initial = 0xC96C5795D7870F42;
crc64 default_crc64;

crc64::crc64(const char * /*randomString*/) {
  crc64::generate_table(crc64::table);
  // crc64::initial = crc64::update(table, 0, randomString);
}

uint64_t crc64::update(uint64_t (&table)[256], uint64_t initial,
                       const std::string &str) {
  return update(table, initial, (const uint8_t *)str.c_str(), str.length());
}

uint64_t crc64::update(const std::string &str) {
  return update(table, crc64::initial, (const uint8_t *)str.c_str(),
                str.length());
}

// uint64_t poly = 0xC96C5795D7870F42;
// uint64_t table[256];
