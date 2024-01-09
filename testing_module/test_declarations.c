#include "test_declarations.h"

void test_result(int result, int test_case) {
  if (result) {
    printf("SUCCESS FOR CASE %d\n", test_case);
  } else {
    printf("FAILURE FOR CASE %d\n", test_case);
  }
}

void s21_strlen_tests(int cases, ...) {
  va_list ap;
  va_start(ap, cases);
  for (int i = 0; i < cases; i++) {
    char* string = va_arg(ap, char*);
    test_result(strlen(string) == s21_strlen(string), i);
  }
  va_end(ap);
}

void s21_strncpy_tests(char* f, char* s, char* t, s21_size_t n) {
  char* cases[3] = {f, s, t};
  char destination[n];
  for (int i = 0; i < 3; i++) {
    test_result(strcmp(s21_strncpy(destination, (const char*)cases[i], n),
                       strncpy(destination, (const char*)cases[i], n)) == 0,
                i);
  }
}