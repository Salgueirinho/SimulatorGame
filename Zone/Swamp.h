#ifndef SWAMP_H
#define SWAMP_H

#include "Zone.h"

class Swamp : public Zone {
	public:
		std::string getType() const override {return "pnt";};
		~Swamp () override = default;
    void work(Resources& resources, int day) override;
};

#endif
