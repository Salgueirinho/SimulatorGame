#ifndef BATTERY_H
#define BATTERY_H

#include "Building.h"

class Battery : public Building {
	public:
		std::string getType() const override {return "bat";};
		void work() const override {};
	private:
		int	electricity = 0;
};

#endif
