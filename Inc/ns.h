#pragma once

#ifndef NS_H
#define NS_H

typedef unsigned long long ull;
typedef enum {
  BIN = 2,
  OCT = 8,
  DEC = 10,
  HEX = 16
} NUMERAL; 

ull to_decimal(const char* number, int base);
void *to_binary(ull decimal);
void *to_octal(ull decimal);

#endif
