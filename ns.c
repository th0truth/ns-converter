#include "ns.h"

void ascii_to_integer(int *res, char number[NUM_SIZE], int offset)
{
  for (int i = 0; number[i+offset] != '\0'; i++) {
    if (number[i+offset] > '9' || number[i+offset] < '0') {
      *res = -1;
    }
    *res = *res * 10 + number[i+offset] - '0';
  }
}


void binToDec(int *n)
{
  int dec = 0, base = 1, reminder;
  while (*n) {
    reminder = *n % 10;
    *n /= 10;
    dec += reminder * base;
    base *= 2;
  }
  *n = dec;
}


void binToOctal(int *n)
{
  int dec = 0, octal = 0, base = 1, reminder;

  // binary → decimal (your original logic)
  while (*n != 0)
  {
    reminder = *n % 10;
    dec += reminder * base;
    base *= 2;
    *n /= 10;
  }

  // decimal → octal
  base = 1;
  while (dec != 0)
  {
    reminder = dec % 8;
    octal += reminder * base;
    base *= 10;
    dec /= 8;
  }

  *n = octal;
}