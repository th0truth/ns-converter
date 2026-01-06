#pragma once

#ifndef NS_H
#define NS_H

#define NUMBER_SIZE 64
#define BUFFER_SIZE 128
#define FORMAT_SIZE 8

int extractNumberFormat(char *buffer, char *number, char *format);
int converter(char *res, char *number, char *format);

#endif
