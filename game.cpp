#include <iostream>
#include "Island.h"
#include "utils.h"

void	startGame()
{
	int	lines;
	int	columns;
	std::string	command;

	std::cout << "";
	lines = getNumberBetween(3, 8, "Number of rows for the island, please: ");
	columns = getNumberBetween(3, 16, "Number of columns for the island, please: ");
	Island	island(lines, columns);
	while (command.compare(0, command.find(" "), "exit"))
	{
		island.display();
		command = getOption({"exit"}, "Command: ");
	}
}
