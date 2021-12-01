#ifndef BUILDINGX_H
#define BUILDINGX_H

#include "Building.h"

class BuildingX : public Building {
	public:
		std::string getType() const override {return "edX";};
		~BuildingX () override {};
		void work() const override {};
};

#endif
