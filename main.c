#include <stdio.h>

#include "s21_string_lib/s21_string.h"
#include "testing_module/test_declarations.h"

int main() {
  char res[20] = "He, World!\n";
  void* bruh = s21_memchr(res, ',', 20);
  char second[8] = ", World!";
  if (bruh != NULL) {
    printf("%s", (char*)bruh);
    printf("%d\n", s21_memcmp(second, bruh, 2000));
  }
  printf("%llu\n", s21_strlen(second));
  char br_Str[64];
  s21_strlen_tests(5, "cheburashka", "beer\0bank", "", "disa", "sasaa");
  s21_strncpy_tests("doggy", "batiskaf", "papanister", 64);
  s21_memcpy(br_Str, "bla bla car", 10);
  printf("%s\n", br_Str);
  s21_memset(br_Str + 2, 's', 5);
  printf("%s\n", br_Str);
  s21_strncat(br_Str, second, 4);
  printf("%s\n", br_Str);
  printf("%s\n", s21_strchr(br_Str, 'Y'));
  printf("%s\n", s21_strchr(br_Str, 's'));
  printf("%d\n", s21_strncmp("dadayagav", "dadayameow", 7));
  printf("%llu\n", s21_strcspn("dadayaboyz", "dadaboy"));
  return 0;
}
