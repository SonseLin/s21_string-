#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  //    if(str == s21_null) {
  //        return  s21_null;
  //    }
  const char *res = (const char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    if (res[i] == c) {
      return (void *)&res[i];
    }
  }
  return s21_null;
}