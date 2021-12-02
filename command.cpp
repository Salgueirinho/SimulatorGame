#include <iostream>
#include <sstream>
#include <vector>
#include "Interface.h"
#include "command.h"
#include "utils.h"

void	getCommand()
{
	std::string	buffer;
	std::getline(std::cin, buffer);
	std::vector<std::string>	command = split(buffer);
}

bool	checkArguments(const std::vector<std::string> &command,
										std::pair<std::string,
										std::vector<std::string>> command_pair)
{
	if (command_pair.second.size() == command.size() - 1)
		return (true);
	else
		return (false);
}

bool	checkCommand(const std::vector<std::string> &command)
{
	for (auto const& elem : Interface::commands)
		if (elem.first == command[0])
			return checkArguments(command, elem);
	return false;
}
