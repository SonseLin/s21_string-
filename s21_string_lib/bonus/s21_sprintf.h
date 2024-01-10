#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include "../s21_string.h"
#include "stdio.h"
#include "string.h"

void get_format_counter(char* format, int* count);
void fill_specifier_array(char* format, char** specifier_array);

#endif  // S21_SPRINTF_H
