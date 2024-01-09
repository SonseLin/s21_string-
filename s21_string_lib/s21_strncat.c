#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  while (*dest != '\0') {
    dest++;
  }
  for (s21_size_t i = 0; i < n; i++, dest++, src++) {
    *dest = *src;
  }
  return dest;
}