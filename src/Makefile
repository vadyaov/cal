CC := gcc
calclib := calc.a

ASAN := #-fsanitize=address -g
CFLAGS := -Wall -Werror -Wextra -std=c11 -pedantic -fanalyzer $(ASAN)
TEST_FLAGS := $(CFLAGS) $(shell pkg-config --cflags check)
GCOV_FLAGS := -fprofile-arcs -ftest-coverage

TST_LIBS ?= $(shell pkg-config --libs check) 
ifeq ($(shell uname), Linux)
	TST_LIBS = $(shell pkg-config --libs check) -lcheck_pic -lpthread -lrt -lsubunit -lm
endif

SRC_FILES := $(shell find . -maxdepth 1 -name "*.c")
SRC_OBJS := $(addprefix ./objects/, $(notdir $(SRC_FILES:.c=.o)))
SRC_INC := $(shell find . -maxdepth 1 -name "*.h")

TEST_FILES := $(shell find ./tests -maxdepth 1 -name "*_test.c")
TEST_OBJS := $(addprefix ./tests/objects/, $(notdir $(TEST_FILES:.c=.o)))
TEST_INC := ./tests/test.h
TEST_MAIN := ./tests/test.c
TEST_MAIN_OBJ := ./tests/objects/test.o
TEST_ALL_OBJS := $(TEST_OBJS) $(TEST_MAIN_OBJS)

all: $(calclib) test #gcov_report

$(calclib): $(SRC_OBJS) $(SRC_INC)
	ar rc $@ $(SRC_OBJS)
	ranlib $@

$(SRC_OBJS): ./objects%.o: .%.c $(SRC_INC)
	@mkdir -p objects
	$(CC) $(CFLAGS) -o $@ -c $<

test: $(calclib) $(TEST_OBJS) $(TEST_MAIN_OBJ) $(TEST_INC)
	$(CC) $(TEST_OBJS) $(TEST_MAIN_OBJ) -o tests/test $(TST_LIBS) -L. $(calclib) #-fsanitize=address -g
	./tests/test

$(TEST_OBJS): ./tests/objects%.o: ./tests/%.c $(TEST_INC)
	@mkdir -p ./tests/objects
	$(CC) $(TEST_FLAGS) -o $@ -c $<

$(TEST_MAIN_OBJ): $(TEST_MAIN)
	@mkdir -p ./tests/objects
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(SRC_OBJS) $(TEST_ALL_OBJS) $(calclib) ./tests/test
	rm -rf ./objects/ ./tests/objects
