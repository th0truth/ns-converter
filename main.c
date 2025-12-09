#include <stdio.h>
#include <stdlib.h>
#include "ns.h"

#define FORMAT_SIZE 3
#define BUFF_SIZE 67

int cmp(char s1[], char s2[])
{
  for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
    if (s1[i] != s2[i]) {
      return (s1[i] > s2[i]) ? 1 : 1;
    }
  }
}


void extractNumFmt(char buff[], char number[], char format[])
{
  int i = 0, j = 0, space = 0;
  for (; buff[i] != '\0'; i++) {
    if (buff[i] != ' ') {
      number[i] = buff[i];  
    } else {
      space = i;
      break;
    }
  }
  number[i+1] = '\0';

  if (!space) {
    printf("No space found");
    exit(1);
  }


  for (j, i = space+1; buff[i] != '\0'; j++, i++) format[j] = buff[i];
  buff[j+1] = '\0';
}

int main(void) {  
  char buff[BUFF_SIZE], number[BUFF_SIZE], format[FORMAT_SIZE];

  fgets(buff, BUFF_SIZE, stdin);

  extractNumFmt(buff, number, format);

  int res = 0;
  for (int i = 0; number[i] != '\0'; i++) {
    if (number[i] != '0') {
      ascii_to_integer(&res, number, 0);
    } else if (number[i] == '0' && number[i+1] == 'b') {
      ascii_to_integer(&res, number, 2);
      if (cmp(format, "dec") == 0) {
        binToDec(&res);
      } else if (cmp(format, "octal") == 0) {
        binToOctal(&res);
      } else if (cmp(format, "hex") == 0) {
        binToDec(&res);
        printf("Output: %X\n", res);
        return 0;
      }  else {
        printf("Invalid numeral-system format.");
      }
      break;
    } else {
      printf("Invalid input");
      break;
    }
  }

  printf("Output: %d\n", res);

  return 0;
}
