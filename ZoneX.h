#ifndef ZONEX_H
#define ZONEX_H

#include "Zone.h"

class ZoneX : public Zone{
	public:
		std::string getType() const override {return "znZ";};
};

#endif
