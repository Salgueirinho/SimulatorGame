#include <iostream>
#include "utils.h"

void	showMenu(void)
{
	string option; 

	while (option.compare("exit"))
	{
		displayFile("mainmenu");
		option = getOption({"play", "info", "exit"});
		if (!option.compare("play"))
			option = "exit";
		else if (!option.compare("info"))
		{
			displayFile("instructions");
			option = getOption({"back", "exit"});
		}
	}
	cout << "See you next time!" << endl;
}
