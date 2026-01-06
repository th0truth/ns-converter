#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns.h"

int extractNumberFormat(char *buffer, char *number, char *format)
{
  int i = 0, space = 0;
  for (; buffer[i] != '\0'; i++) {
    if (buffer[i] != ' ') {
      number[i] = buffer[i];  
    } else {
      space = i;
      break;
    }
  }
  number[i+1] = '\0';
  
  if (!space) {
    return 1;
  }

  int j = 0;
  for (i = space+1; buffer[i] != '\0'; j++, i++)
    format[j] = buffer[i];
    
  return 0;
}


int compare(char *s1, char *s2)
{
  for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
    if (s1[i] != s2[i]) {
      return (s1[i] > s2[i]) ? 1 : 1;
    }
  }
}


int checkBin(char *number)
{
  int i = 0;
  while (number[i] != '\0') {
    if (number[i] != '0' && number[i] != '1') {
      return 0;
    }
    i++;
  }
  return 1;
}


long binToDec(const char *bin)
{
  int dec = 0, base = 1, reminder;
  
  while (*bin) {
    dec = dec * 2 + (*bin - '0');
    bin++;
  }

  return dec;
}


long binToOctal(const char *bin)
{
  int octal = 0, base = 1, reminder;

  // Binary to decimal
  long dec = binToDec(bin);

  // Decimal to octal
  while (dec != 0)
  {
    reminder = dec % 8;
    octal += reminder * base;
    base *= 10;
    dec /= 8;
  }

  return octal;
}


int converter(char *res, char *number, char *format)
{
  for (int i = 0; number[i] != '\0'; i++) {
    if (number[0] == '0') {
      if (number[1] == 'b' && checkBin(number + 2) == 1) {
        if (compare(format, "dec") == 0) {
          snprintf(res, BUFFER_SIZE, "%ld", binToDec(number + 2));
        } else if (compare(format, "oct") == 0) {
          snprintf(res, BUFFER_SIZE, "%ld", binToOctal(number + 2));
        } else if (compare(format, "hex") == 0) {
          snprintf(res, BUFFER_SIZE, "%X", binToDec(number + 2));
        } else if (compare(format, "bin") == 0) {
          fprintf(stderr, "Please, enter a valid format: `dec`, `oct` or `hex`\n");
          return 1;
        } 
        else {
          fprintf(stderr, "Invalid converter format.\n");
          return 1;
        }
      }
    } 
  }
  return 0;
}