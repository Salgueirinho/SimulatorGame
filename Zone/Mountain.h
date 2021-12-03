#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include "Zone.h"

class Mountain : public Zone {
	public:
		std::string getType() const override {return "mnt";};
		~Mountain() override = default;
};

#endif
