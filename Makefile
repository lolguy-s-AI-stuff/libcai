UNAME_S = $(shell uname -s)

CC = clang++
CFLAGS = -O2 -g -Wall -Wextra -Wpedantic -Wstrict-aliasing -Wc++11-narrowing -Wvla-extension
CFLAGS += -Wno-pointer-arith -Wno-newline-eof -Wno-unused-parameter -Wno-gnu-statement-expression
CFLAGS += -Wno-gnu-compound-literal-initializer -Wno-gnu-zero-variadic-macro-arguments
CFLAGS += -Iinclude

SRC  = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) $(wildcard src/*.cpp) $(wildcard src/**/**/*.cpp) $(wildcard src/**/**/**/*.cpp)
OBJ  = $(SRC:.cpp=.o)
BIN  = ./bin


.PHONY: all clean

all: dirs lib

dirs:
	mkdir -p ./$(BIN)

lib: $(OBJ)
	ar rcs $(BIN)/libcai.a $^

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BIN) $(OBJ)