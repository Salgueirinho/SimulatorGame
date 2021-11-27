#include <iostream>
#include "Island.h"
#include "utils.h"

void	startGame(void)
{
	int	lines;
	int	columns;
	string	command;

	cout << "Number of lines for the island, please: ";
	lines = getNumberBetween(3, 8);
	cout << "Number of columns for the island, please: ";
	columns = getNumberBetween(3, 16);
	Island	island(lines, columns);
	while (command.compare(0, command.find(" "), "exit"))
	{
		island.display();
		cout << "Your command: ";
		command = getOption({"exit"});
	}
}
