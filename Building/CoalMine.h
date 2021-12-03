#ifndef COALMINE_H
#define COALMINE_H

#include "Building.h"

class CoalMine : public Building {
	public:
		std::string getType() const override {return "mnC";};
		void work() const override {};
		~CoalMine() override = default;
	private:
		int	level = 1;
};

#endif
