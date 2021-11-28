#include <iostream>
#include "game.h"
#include "utils.h"

void	showMenu(void)
{
	std::string option; 

	while (option.compare("exit"))
	{
		displayFile("mainmenu");
		std::cout << "Your option: ";
		option = getOption({"play", "info", "exit"});
		option = option.substr(0, option.find(" "));
		if (!option.compare("play"))
			startGame();
		else if (!option.compare("info"))
		{
			displayFile("instructions");
			option = getOption({"back", "exit"});
		}
	}
	std::cout << "See you next time!" << std::endl;
}
