#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "Building.h"

class PowerPlant : public Building {
	public:
		PowerPlant();
		std::string getType() const override {return "cen";};
		void work() const override {};
	private:
		int	coal;
};

#endif
