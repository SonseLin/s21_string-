//
// Created by Sonse on 05.01.2024.
//

#ifndef S21_STRING_H
#define S21_STRING_H

#include "../defines.h"
#include "stdarg.h"
#include "stdlib.h"

// manipulating by memory
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);

// manipulating by objects itself
s21_size_t s21_strlen(const char *str);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);

// bonus
int s21_sprintf(char *res, const char *format, ...);
int s21_atoi(const char *str);
char s21_ctoi(char c);

#endif  // S21_STRING_H
