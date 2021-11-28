#include <iostream>
#include "Island.h"
#include "utils.h"

void	startGame(void)
{
	int	lines;
	int	columns;
	std::string	command;

	std::cout << "Number of lines for the island, please: ";
	lines = getNumberBetween(3, 8);
	std::cout << "Number of columns for the island, please: ";
	columns = getNumberBetween(3, 16);
	Island	island(lines, columns);
	while (command.compare(0, command.find(" "), "exit"))
	{
		island.display();
		std::cout << "Your command: ";
		command = getOption({"exit"});
	}
}
