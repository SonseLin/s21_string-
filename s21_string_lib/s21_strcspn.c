#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int j = 0;
  s21_size_t len = 0;
  for (char *ptr = (char *)str1; *ptr != '\0' && j != -1; ptr++) {
    if (str2[j] == '\0')
      j = -1;
    else {
      if (*ptr == str2[j]) {
        j++;
      }
      len++;
    }
  }
  return len;
}