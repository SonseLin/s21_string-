#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *first = (const char *)str1;
  const char *last = (const char *)str2;
  int res = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (first[i] > last[i] && res >= 0)
      res++;
    else if (first[i] < last[i] && res <= 0)
      res--;
  }
  return res;
}