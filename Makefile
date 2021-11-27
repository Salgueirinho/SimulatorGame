NAME = game

all:
	@g++ *.cpp -Wall -Wextra -Werror -o $(NAME)

run: all
	./$(NAME)

clean:
	@rm $(NAME)
