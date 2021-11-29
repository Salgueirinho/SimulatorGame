#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <map>

class	Interface {
	public:
		void	start();
		void	game();
		void	createLookUpTable();
		std::map<std::string, std::string>	lut;
	private:
};

#endif
