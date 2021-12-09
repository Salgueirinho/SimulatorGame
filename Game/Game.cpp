#include <sstream>
#include <vector>
#include "Game.h"
#include "../Interface/Interface.h"
#include "../utils/utils.h"
#include "../error/error.h"

std::map<std::string, std::vector<std::string>> Game::commands = {
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

void	Game::start()
{

}

void	Game::executeCommand(const std::vector<std::string> &command)
{
	if (command[0] == "exit")
		exit = true;
}

bool	Game::validateArgsFormat(const std::vector<std::string> &command)
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

bool	Game::validateArgsNumber(const std::vector<std::string> &command, const std::pair<std::string, std::vector<std::string>> &command_pair)
{
	if (command_pair.second.size() == command.size() - 1
			|| (command_pair.first == "list" && command.size() == 1))
		return true;
	return false;
}

int	Game::checkCommand(const std::vector<std::string> &command)
{
	for (auto const& elem : Game::commands)
	{
		if (elem.first == command[0])
		{
			if (validateArgsNumber(command, elem))
			{
				if (validateArgsFormat(command))
					return 0;
				else
					return FORMAT_ARGS_ERROR;
			}
			else
				return NUMBER_ARGS_ERROR;
		}
	}
	return COMMAND_ERROR;
}
