#ifndef GAME_H
#define GAME_H

#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "../Island/Island.h"

class	Game {
	public:
		static	std::map<std::string, std::vector<std::string>> commands;
		int	executeCommand(const std::vector<std::string> &command);
		static int	checkCommand(const std::vector<std::string> &command);
		bool	exit = false;
		Island	*island = nullptr;
		std::string	command_output = "";
		// commands
		void	list();
		int	list(int x, int y);
	private:
		static bool	validateArgsNumber(const std::vector<std::string> &command, const std::pair<std::string, std::vector<std::string>> &command_pair);
		static bool	validateArgsFormat(const std::vector<std::string> &command);
};

#endif
