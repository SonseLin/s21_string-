#include "s21_sprintf.h"

int s21_sprintf(char *res, const char *format, ...) {
  va_list input = {0};
  int flags_count = 0;
  va_start(input, format);
  char *res_begining = res;
  char *list_of_specifiers[1024];
  get_format_counter((char *)format, &flags_count);
  while (*format != '\0') {
    if (*format == '%') {
      format++;
      if (*format == 'd') {
        int arg = va_arg(input, int);
        char arg_str[12];
        // s21_atoi(arg);
        strcpy(res, arg_str);
        while (*res != '\0') {
          res++;
        }
      } else if (*format == 's') {
        char *arg = va_arg(input, char *);
        strcpy(res, arg);
        while (*res != '\0') {
          res++;
        }
      } else {
        *res = *format;
        res++;
      }
      format++;
    }
  }
  va_end(input);

  return res - res_begining;
}

int s21_atoi(const char *str) {
  int res = 0;
  int sign = 1;
  int overflow = 0;

  while (*str == ' ') str++;
  if (*str == '+') str++;

  if (*str == '-') {
    sign = -1;
    str++;
  }
  while (*str && *str >= '0' && *str <= '9') {
    res = res * 10 + s21_ctoi(*str);
    if (res < 0) {
      overflow++;
      break;
    }
    str++;
  }
  if (overflow)
    res = sign > 0 ? INT32_MAX : INT32_MIN;
  else
    res *= sign;
  return res;
}

char s21_ctoi(char c) { return c - '0'; }

void get_format_counter(char *format, int *count) {
  int res = 0;
  int is_last_specifier = 0;
  for (char *ptr = format; *ptr != '\0'; ptr++) {
    if (*ptr == '%')
      is_last_specifier++;
    else
      is_last_specifier = 0;
    if (is_last_specifier == 1) res++;
  }
  *count = res;
}

void fill_specifier_array(char *format, char **specifier_array) {
  int position = 0;
  char current_specifier[64];
  int any_symbol_in_specifier = 0;
  int length = 0;
  char *start;
  for (char *ptr = format; *ptr != '\0'; ptr++) {
    if (*ptr == '%' && any_symbol_in_specifier > 0) {
      strncpy(current_specifier, start, length);
      for (int i = 0; i < length; i++) {
        specifier_array[position] = current_specifier;
      }
      printf("%s\n", current_specifier);
      position++;
      start = ptr;
      length = 1;
      any_symbol_in_specifier = 0;
    } else if (*ptr == '%' && start == NULL) {
      start = ptr;
      length = 1;
    } else {
      length++;
    }
    if (*ptr != '%') any_symbol_in_specifier++;
  }
  strncpy(current_specifier, start, length);
  specifier_array[position] = current_specifier;
  printf("%s\n", current_specifier);
}