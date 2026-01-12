#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "utils.h"
#include "ns.h"

// Convert string to a long number
ull to_decimal(const char* number, int base) {
  char *endptr;

  ull value = strtoull(number, &endptr, base);
  if (*endptr != '\0') {
    fprintf(stderr, "Conversion error: invalid number\n");
    exit(1);
  }

  if (errno == ERANGE) {
    fprintf(stderr, "Number too large for uint64_t\n");
    exit(1);
  }

  return value;
}

// Convert decimal to an octal string
void *to_octal(ull decimal) {
  if (decimal == 0) { return NULL; }
  
  char temp[128];
  int i = 0;

  while (decimal > 0) {
    temp[i++] = (decimal % 8) + '0';
    decimal /= 8;
  }

  char *octal = malloc(i + 1);
  for (int j = 0; j < i; j++) {
    octal[j] = temp[i - 1 - j];
  }
  octal[i] = '\0';

  return octal;
}

// Convert decimal to a binary string
void* to_binary(ull decimal) {
  char *bin = malloc(65 * sizeof(char));
  if (bin == NULL) { return NULL; }

  int i = 0;
  if (decimal == 0) {
    bin[i++] = '0';
  } else {
    while (decimal > 0) {
      bin[i++] = (decimal % 2) + '0';
      decimal /= 2;
    }
  }
  bin[i] = '\0';

  // Reverse the string
  for (int j = 0; j < i / 2; j++) {
    char temp = bin[j];
    bin[j] = bin[i-1-j];
    bin[i-1-j] = temp;
  }

  return bin;
}