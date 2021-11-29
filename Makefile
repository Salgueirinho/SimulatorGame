NAME = game

all:
	@g++ *.cpp -Wall -Wextra -Werror -pedantic -o $(NAME)

run: all
	./$(NAME)

clean:
	@rm $(NAME)
