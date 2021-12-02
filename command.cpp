#include <iostream>
#include <sstream>
#include <vector>
#include "Interface.h"
#include "command.h"
#include "utils.h"

std::string	getCommand()
{
	std::string	buffer;
	bool				validity = false;
	std::vector<std::string>	command = {""};

	while (!validity)
	{
		std::cout << "Command: ";
		std::getline(std::cin, buffer);
		command = split(buffer);
		validity = checkCommand(command);
	}
	executeCommand(command);
	return command[0];
}

void	executeCommand(const std::vector<std::string> &command)
{
	(void) command;
}

bool	checkFormatArguments(const std::vector<std::string> &command)
{
	if (command[0] == "exec" || (command[0] == "list" && command.size() == 1)
	|| command[0] == "next" || command[0] == "save" || command[0] == "load"
	|| command[0] == "apaga" || command[0] == "config" || command[0] == "exit")
		return true;
	else if (command[0] == "liga" || command[0] == "des" || command[0] == "list"
	|| command[0] == "vende")
		return toInt(command[1]) != -1 && toInt(command[2]) != -1;
	else if (command[0] == "cons")
		return (command[1] == "mnF" || command[1] == "mnC" || command[1] == "bat"
		|| command[1] == "cen" || command[1] == "fun" || command[1] == "edX") &&
		toInt(command[2]) != -1 && toInt(command[3]) != -1;
	else if (command[0] == "move")
		return toFloat(command[1]) != -1 && toInt(command[2]) != -1 &&
		toInt(command[3]) != -1;
	else if (command[0] == "vende")
		return (command[1] == "ferro" || command[1] == "aco" || command[1] == "carvao"
		|| command[1] == "mad" || command[1] == "viga" || command[1] == "eletr") &&
		toInt(command[2]) != -1;
	else if (command[0] == "cont")
		return command[1] == "min" || command[1] == "len" || command[1] == "ope";
	else if (command[0] == "debcash")
		return toInt(command[1]) != -1;
	else if (command[0] == "debed")
		return (command[1] == "mnF" || command[1] == "mnC" || command[1] == "bat"
		|| command[1] == "cen" || command[1] == "fun" || command[1] == "edX") &&
		toInt(command[2]) != -1 && toInt(command[3]) != -1;
	else if (command[0] == "debkill")
		return (toFloat(command[1]) != -1);
	return false;
}

bool	checkNumberArguments(const std::vector<std::string> &command, std::pair<std::string, std::vector<std::string>> command_pair)
{
	if (command_pair.second.size() == command.size() - 1)
	{
		if (checkFormatArguments(command))
			return true;
		else
			std::cout << "Format of arguments invalid!" << std::endl;
	}
	else if (command_pair.first == "list" && command.size() == 1)
		return true;
	else
		std::cout << "Number of arguments invalid!" << std::endl;
	return false;
}

bool	checkCommand(const std::vector<std::string> &command)
{
	for (auto const& elem : Interface::commands)
		if (elem.first == command[0])
			return checkNumberArguments(command, elem);
	return false;
}
