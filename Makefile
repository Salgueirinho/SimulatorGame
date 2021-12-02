NAME = game

SOURCES =	Command.cpp \
					Interface.cpp \
					utils.cpp \
					main.cpp \
					Island.cpp \
					Building/Building.cpp \
					Zone/Zone.cpp \
					Zone/Forest.cpp \

OBJECTS = $(patsubst %.cpp, .obj/%.o, $(SOURCES))

CC = g++

CFLAGS = -Wall -Wextra -Werror -pedantic -I.

all: $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS)

.obj/%.o: %.cpp
	@mkdir -p .obj
	@mkdir -p .obj/Building
	@mkdir -p .obj/Worker
	@mkdir -p .obj/Zone
	$(CC) -c -o $@ $< $(CFLAGS)

run: all
	./$(NAME)

clean:
	@rm -f $(NAME)

fclean:
	@rm -rf .obj

re: fclean all
