#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include <string>
#include <map>

class	Interface {
	public:
		static	std::map<std::string, std::vector<std::string>> commands;
		void	start() const;
		void	game() const;
};

#endif
