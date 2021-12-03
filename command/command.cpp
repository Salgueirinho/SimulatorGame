#include <iostream>
#include <sstream>
#include <vector>
#include "command.h"
#include "../Interface.h"
#include "../utils.h"

std::vector<std::string>	getCommand()
{
	std::string	buffer;
	bool				validity = false;
	std::vector<std::string>	command;

	while (!validity)
	{
		std::cout << "Command: ";
		std::getline(std::cin, buffer);
		if (0 < buffer.size())
		{
			command = split(buffer);
			validity = checkCommand(command);
		}
	}
	return command;
}

void	executeCommand(const std::vector<std::string> &command)
{
	(void) command;
}

bool	checkFormatArguments(const std::vector<std::string> &command)
{
	if (contains({"exec", "next", "save", "load", "apaga", "config", "exit"}, command[0])
	|| (command[0] == "list" && command.size() == 1))
		return true;
	else if (contains({"liga", "des", "list", "vende"}, command[0]))
		return toInt(command[1]) != -1 && toInt(command[2]) != -1;
	else if (contains({"cons", "vende", "debed"}, command[0]))
		return (contains({"mnF","mnC","bat","cen","fun","edX"}, command[1])
		&& toInt(command[2]) != -1 && toInt(command[3]) != -1);
	else if (command[0] == "move")
		return toFloat(command[1]) != -1 && toInt(command[2]) != -1
		&& toInt(command[3]) != -1;
	else if (command[0] == "cont")
		return contains({"len", "min", "ope"}, command[1]);
	else if (command[0] == "debcash")
		return toInt(command[1]) != -1;
	else if (command[0] == "debkill")
		return (toFloat(command[1]) != -1);
	return false;
}

bool	checkNumberArguments(const std::vector<std::string> &command, std::pair<std::string, std::vector<std::string>> command_pair)
{
	if (command_pair.second.size() == command.size() - 1)
		if (checkFormatArguments(command))
			return true;
	if (command_pair.first == "list" && command.size() == 1)
		return true;
	std::cout << "Format of arguments invalid!" << std::endl;
	return false;
}

bool	checkCommand(const std::vector<std::string> &command)
{
	for (auto const& elem : Interface::commands)
		if (elem.first == command[0])
			return checkNumberArguments(command, elem);
	return false;
}
