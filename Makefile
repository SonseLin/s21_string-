cc = gcc
flags = -Wall -Werror -Wextra -std=c11
CCF = $(cc) $(flags)

SOURCES = $(wildcard s21_string_lib/*.c)
OBJS = $(SOURCES:.c=.o)

TEST_SOURCES = $(wildcard testing_module/*.c)
TEST_OBJS = $(TEST_SOURCES:.c=.o)

LIB_PATH = s21_string.a

all: lib tests
	$(CCF) $(OBJS) main.c -o s21_strings -L. $(LIB_PATH) $(TEST_OBJS)

lib: $(OBJS)
	ar rcs $(LIB_PATH) $(OBJS)

tests: $(TEST_OBJS)

clear:
	rm -f *.o *.a s21_string_lib/*.o testing_module/*.o 

rebuild: clear all
	./s21_strings