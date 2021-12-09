#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include <string>
#include <map>
#include "../Game/Game.h"

class	Interface {
	public:
		explicit	Interface(Game *g) : game(g) {};
		static std::vector<std::string>	getCommand();
		void	menu();
		void	start();
	private:
		Game *game;
};

#endif
