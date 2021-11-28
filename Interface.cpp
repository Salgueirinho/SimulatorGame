#include <iostream>
#include "Interface.h"
#include "game.h"
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
