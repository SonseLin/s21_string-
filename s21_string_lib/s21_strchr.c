#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  for (const char *ptr = str; *ptr != '\0'; ptr++) {
    if (*ptr == c) return (char *)ptr;
  }
  return s21_null;
}