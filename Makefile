NAME = sim

SOURCES = *.cpp \

CC = g++

CFLAGS = -Wall -Werror -Wextra

all: clean $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SOURCES) -o $(NAME)

clean:
	@rm -f ./$(NAME)
