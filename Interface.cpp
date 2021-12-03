#include <iostream>
#include "Interface.h"
#include "command/command.h"
#include "Island.h"
#include "utils.h"

std::map<std::string, std::vector<std::string>> Interface::commands = {
	{"exec",		{"nomeFicheiro"}},
	{"cons",		{"tipo", "linha", "coluna"}},
	{"liga",		{"linha", "coluna"}},
	{"des",			{"linha", "coluna"}},
	{"move",		{"id", "linha", "coluna"}},
	{"vende",		{"tipo", "quanto"}},
	{"cont",		{"tipo"}},
	{"list",		{"linha", "coluna"}},
	{"vende",		{"linha", "coluna"}},
	{"next",		{}},
	{"save",		{"nome"}},
	{"load",		{"nome"}},
	{"apaga",		{"ficheiro"}},
	{"config",	{"valor"}},
	{"debcash",	{"valor"}},
	{"debed",		{"tipo", "linha", "coluna"}},
	{"debkill",	{"id"}},
	{"exit",		{}}
};

void	Interface::start()
{
	std::string option; 

	while (option != "exit")
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

void	Interface::game()
{
	std::vector<std::string>	command = {""};

	Island	island;
	while (command[0] != "exit")
	{
		island.displayZones();
		command = getCommand();
		if (command[0] != "exit")
			executeCommand(command);
	}
}
