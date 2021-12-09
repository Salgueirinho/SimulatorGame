#include <iostream>
#include "Interface.h"
#include "../Island/Island.h"
#include "../utils/utils.h"
#include "../error/error.h"

void	Interface::menu()
{
	std::string option; 

	while (option != "exit")
	{
		displayFile("textfiles/mainmenu.txt");
		option = getOption({"play", "info", "exit"}, "Option: ");
		if (option == "play")
			start();
		else if (option == "info")
		{
			displayFile("textfiles/info.txt");
			option = getOption({"back", "exit"}, "Option: ");
		}
	}
	std::cout << "See you next time!" << std::endl;
}

void	Interface::start()
{
	int	rows = getNumberBetween(3, 8, "Rows for the island, please: ");
	int	columns = getNumberBetween(3, 16, "Columns for the island, please: ");
	Island island(rows, columns);
	game->island = &island;
	game->exit = false;
	std::vector<std::string>	command;
	while (!game->exit)
	{
		std::cout << game->island->getAsString();
		command = getCommand();
		game->executeCommand(command);
	}
}

std::vector<std::string>	Interface::getCommand()
{
	std::string	buffer;
	int	error_code = 1;
	std::vector<std::string>	command;

	while (error_code)
	{
		std::cout << "Command: ";
		std::getline(std::cin, buffer);
		if (!buffer.empty())
		{
			command = split(buffer);
			error_code = game->checkCommand(command);
			std::cout << parseErrorCode(error_code);
		}
	}
	return command;
}
