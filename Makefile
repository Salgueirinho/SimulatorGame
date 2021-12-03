NAME = game

SOURCES =	Interface/Interface.cpp \
		command/command.cpp \
		utils/utils.cpp \
		main.cpp \
		Island/Island.cpp \
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
	@mkdir -p .obj/Interface
	@mkdir -p .obj/Building
	@mkdir -p .obj/command
	@mkdir -p .obj/Island
	@mkdir -p .obj/Worker
	@mkdir -p .obj/utils
	@mkdir -p .obj/Zone
	@echo Compiling $@...
	@$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -rf .obj

re: fclean all
