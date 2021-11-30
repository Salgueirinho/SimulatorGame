#ifndef COALMINE_H
#define COALMINE_H

#include "Building.h"

class CoalMine : public Building {
	public:
		std::string getType() const override {return "mnC";};
		void work() const override {};
	private:
		int	level = 1;
};

#endif
