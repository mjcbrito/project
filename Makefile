CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))
BIN = bin/contest_game

all: $(BIN)

$(BIN): $(OBJ)
	@mkdir -p bin
	$(CC) $(CFLAGS) $(OBJ) -o $@

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -rf bin

re: fclean all

valgrind: $(BIN)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/contest_game

# Phony Targets
.PHONY: all clean fclean re valgrind
