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
		if (!validity)
			std::cout << "Command invalid!" << std::endl;
	}
	std::cout << "Command valid!" << std::endl;
	return command[0];
}

bool	checkFormatArguments(const std::vector<std::string> &command)
{
	return true;
}

bool	checkNumberArguments(const std::vector<std::string> &command, std::pair<std::string, std::vector<std::string>> command_pair)
{
	if (command_pair.second.size() == command.size() - 1)
		return checkFormatArguments(command);
	else if (command_pair.first == "list" && command.size() == 1)
		return true;
	else
		return false;
}

bool	checkCommand(const std::vector<std::string> &command)
{
	for (auto const& elem : Interface::commands)
		if (elem.first == command[0])
			return checkNumberArguments(command, elem);
	return false;
}
