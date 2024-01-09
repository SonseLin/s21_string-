//
// Created by Sonse on 06.01.2024.
//

#ifndef TEST_DECLARATIONS_H
#define TEST_DECLARATIONS_H

#include "../defines.h"
#include "../s21_string_lib/s21_string.h"
#include "stdio.h"
#include "strings.h"

#define BY_SIZE 0
#define BY_COMPARISON 1

void test_result(int result, int test_case);
void s21_strlen_tests(int cases, ...);
void s21_strncpy_tests(char* f, char* s, char* t, s21_size_t n);

#endif  // TEST_DECLARATIONS_H
