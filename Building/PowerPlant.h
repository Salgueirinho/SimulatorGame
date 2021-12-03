#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "Building.h"

class PowerPlant : public Building {
	public:
		std::string getType() const override {return "cen";};
		void work() const override = default;
		~PowerPlant() override {};
	private:
		int	coal = 0;
};

#endif
