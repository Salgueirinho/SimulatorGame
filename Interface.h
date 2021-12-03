#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include <string>
#include <map>

class	Interface {
	public:
		static	std::map<std::string, std::vector<std::string>> commands;
		static void	start();
		static void	game();
};

#endif
