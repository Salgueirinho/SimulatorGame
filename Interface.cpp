#include <iostream>
#include <fstream>
#include "Interface.h"
#include "Island.h"
#include "utils.h"

void	Interface::start()
{
	std::string option; 

	while (option.compare("exit"))
	{
		displayFile("mainmenu");
		option = getCommand({"play", "info", "exit"}, "Option: ").substr(0, option.find(' '));
		if (option == "play")
			game();
		else if (option == "info")
		{
			displayFile("instructions");
			option = getCommand({"back", "exit"}, "Option: ").substr(0, option.find(' '));
		}
	}
	std::cout << "See you next time!" << std::endl;
}

void	Interface::game()
{
	std::string	command;

	Island	island(getNumberBetween(3, 8, "Rows for the island, please: "), getNumberBetween(3, 16, "Columns for the island, please: "));
	this->createLookUpTable();
	while (command.compare(0, command.find(' '), "exit"))
	{
		island.displayZones();
		command = getCommand({"exit"}, "Command: ");
	}
}

void	Interface::createLookUpTable()
{
	std::fstream	fs;
	std::string	buffer;
	fs.open("lookuptable");
	if (!fs)
	{
		std::cout << "Unable to open file\"lookuptable\"." << std::endl;
		return ;
	}
	while (!fs.eof())
	{
		std::getline(fs, buffer);
		lut.insert(std::pair<std::string, std::string>(buffer.substr(0, buffer.find(' ')), buffer.substr(buffer.find(' ') + 1, buffer.size())));
	}
	fs.close();
}
