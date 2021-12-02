NAME = game

SOURCES =	command.cpp \
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

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo Compiling executable \'$(NAME)\'...
	@$(CC) -o $(NAME) $(OBJECTS)

.obj/%.o: %.cpp
	@mkdir -p .obj
	@mkdir -p .obj/Building
	@mkdir -p .obj/Worker
	@mkdir -p .obj/Zone
	@echo Compiling $@...
	@$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -rf .obj

re: fclean all
