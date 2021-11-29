#include <iostream>
#include "Interface.h"
#include "Island.h"
#include "utils.h"

void	Interface::showMenu() const
{
	std::string option; 

	while (option.compare("exit"))
	{
		displayFile("mainmenu");
		option = getOption({"play", "info", "exit"}, "Option: ");
		option = option.substr(0, option.find(" "));
		if (!option.compare("play"))
			startGame();
		else if (!option.compare("info"))
		{
			displayFile("instructions");
			option = getOption({"back", "exit"}, "Option: ");
		}
	}
	std::cout << "See you next time!" << std::endl;
}

void	Interface::startGame() const
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
		island.displayZones();
		command = getOption({"exit"}, "Command: ");
	}
}
