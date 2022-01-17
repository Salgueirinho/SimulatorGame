#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include "Zone.h"

class Mountain : public Zone {
	public:
    float iron;
		std::string getType() const override {return "mnt";};

    void work(Resources& resources, int day) override;
		~Mountain() override = default;
};

#endif
