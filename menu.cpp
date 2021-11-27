#include <iostream>
#include "game.h"
#include "utils.h"

void	showMenu(void)
{
	string option; 

	while (option.compare("exit"))
	{
		displayFile("mainmenu");
		option = getOption({"play", "info", "exit"});
		if (!option.compare("play"))
			startGame();
		else if (!option.compare("info"))
		{
			displayFile("instructions");
			option = getOption({"back", "exit"});
		}
	}
	cout << "See you next time!" << endl;
}
