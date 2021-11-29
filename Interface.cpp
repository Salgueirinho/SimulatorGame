#include <iostream>
#include "Interface.h"
#include "Island.h"
#include "utils.h"

void	Interface::start() const
{
	std::string option; 

	while (option.compare("exit"))
	{
		displayFile("mainmenu");
		option = getCommand({"play", "info", "exit"}, "Option: ").substr(0, option.find(" "));
		if (option == "play")
			game();
		else if (option == "info")
		{
			displayFile("instructions");
			option = getCommand({"back", "exit"}, "Option: ").substr(0, option.find(" "));
		}
	}
	std::cout << "See you next time!" << std::endl;
}

void	Interface::game() const
{
	std::string	command;

	Island	island(getNumberBetween(3, 8, "Rows for the island, please: "), getNumberBetween(3, 16, "Columns for the island, please: "));
	while (command.compare(0, command.find(" "), "exit"))
	{
		island.displayZones();
		command = getCommand({"exit"}, "Command: ");
	}
}
