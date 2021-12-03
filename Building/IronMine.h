#ifndef IRONMINE_H
#define IRONMINE_H

#include "Building.h"

class IronMine : public Building {
	public:
		std::string getType() const override {return "mnF";};
		void work() const override = default;
		~IronMine() override {};
	private:
		int	iron = 0;
		int	level = 1;
};

#endif
