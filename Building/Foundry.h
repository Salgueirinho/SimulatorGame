#ifndef FOUNDRY_H
#define FOUNDRY_H

#include "Building.h"

class Foundry : public Building {
	public:
		std::string getType() const override {return "fun";};
		void work() const override {};
		~Foundry() override = default;
	private:
		int	steel = 0;
};

#endif
