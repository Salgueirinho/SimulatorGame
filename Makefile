NAME = game

SOURCES =	Interface/Interface.cpp \
		utils/utils.cpp \
		main.cpp \
		Island/Island.cpp \
		Building/Building.cpp \
		Zone/Zone.cpp \
		Zone/Forest.cpp \
		Game/Game.cpp \
		error/error.cpp \

OBJECTS = $(patsubst %.cpp, .obj/%.o, $(SOURCES))

CC = g++

CFLAGS = -Wall -Wextra -Werror -pedantic -I.

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo Compiling executable \'$(NAME)\'...
	@$(CC) -o $(NAME) $(OBJECTS)

.obj/%.o: %.cpp
	@mkdir -p .obj
	@mkdir -p .obj/Interface
	@mkdir -p .obj/Building
	@mkdir -p .obj/Island
	@mkdir -p .obj/Worker
	@mkdir -p .obj/utils
	@mkdir -p .obj/Zone
	@mkdir -p .obj/Game
	@mkdir -p .obj/error
	@echo Compiling $@...
	@$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -rf .obj

re: fclean all
