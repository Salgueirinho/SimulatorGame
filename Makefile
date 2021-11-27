all:
	@g++ *.cpp -Wall -Wextra -Werror -o sim

run: all
	./sim

clean:
	@rm sim
