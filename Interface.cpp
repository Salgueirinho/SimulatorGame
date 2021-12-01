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
		option = getOption({"play", "info", "exit"}, "Option: ");
		if (option == "play")
			game();
		else if (option == "info")
		{
			displayFile("info");
			option = getOption({"back", "exit"}, "Option: ");
		}
	}
	std::cout << "See you next time!" << std::endl;
}

void	Interface::game() const
{
	std::string	command;

	Island	island;
	while (command != "exit")
	{
		island.displayZones();
		command = getOption({"exit"}, "Command: ");
	}
}
