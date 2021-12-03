NAME = game

SOURCES =	Interface.cpp \
					command/command.cpp \
					utils.cpp \
					main.cpp \
					Island.cpp \
					Building/Building.cpp \
					Zone/Zone.cpp \
					Zone/Forest.cpp \

OBJECTS = $(patsubst %.cpp, .obj/%.o, $(SOURCES))

CC = g++

CFLAGS = -Wall -Wextra -Werror -pedantic -I.

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo Compiling executable \'$(NAME)\'...
	@$(CC) -o $(NAME) $(OBJECTS)

.obj/%.o: %.cpp
	@mkdir -p .obj
	@mkdir -p .obj/Building
	@mkdir -p .obj/Worker
	@mkdir -p .obj/Zone
	@mkdir -p .obj/command
	@echo Compiling $@...
	@$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -rf .obj

re: fclean all
