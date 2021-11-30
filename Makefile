SOURCES =							\
			Building/*.cpp	\
			Zone/*.cpp			\
			*.cpp

CFLAGS = -Wall -Wextra -Werror -pedantic

NAME = game

all:
	@g++ $(SOURCES) $(CFLAGS) -o $(NAME)

run: all
	./$(NAME)

clean:
	@rm $(NAME)
