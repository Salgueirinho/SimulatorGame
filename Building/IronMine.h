#ifndef IRONMINE_H
#define IRONMINE_H

#include "Building.h"

class IronMine : public Building {
	public:
		IronMine();
		std::string getType() const override {return "mnF";};
		void work() const override {};
	private:
		int	iron;
		int	level;
};

#endif
