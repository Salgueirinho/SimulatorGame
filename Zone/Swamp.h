#ifndef SWAMP_H
#define SWAMP_H

#include "Zone.h"

class Swamp : public Zone {
	public:
		std::string getType() const override {return "pnt";};
};

#endif
