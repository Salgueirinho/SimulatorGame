NAME = sim

SOURCES = *.cpp \

CC = g++

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SOURCES) -o $(NAME)

clean:
	@rm $(NAME)

re: clean $(NAME)
