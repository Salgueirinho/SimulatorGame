#include <iostream>
#include "Interface.h"
//#include "../utils/utils.h"
#include "../errors/errors.h"

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
    game->day = 1;
    game->time_of_day = "Morning";
    game->resources.cash = 200;
	std::vector<std::string>	command;
	while (!game->exit)
	{
    game->command_output = "";
    game->checkEndOfGame();
    std::cout << game->getEssentialInfo();

    if (game->time_of_day == "Morning")
    {
        std::cout << "Simulating Morning..." << std::endl;
        game->simulateMorning(game->day);
        game->nextTimeOfDay();
    }
    else if(game->time_of_day == "Noon")
    {
        command = getCommand();
        game->executeCommand(command);
        std::cout << game->command_output << std::endl;
    }
    else if (game->time_of_day == "Dusk")
    {
        std::cout << "Simulating Dusk..." << std::endl;
        game->simulateDusk(game->day);
        game->nextTimeOfDay();
    }
    std::cout << game->island->getAsString();
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
			error_code = Game::checkCommand(command);
			std::cout << parseErrorCode(error_code);
		}
	}
	return command;
}
