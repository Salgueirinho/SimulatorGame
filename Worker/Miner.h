#ifndef MINER_H
#define MINER_H

#include "Worker.h"

class Miner : public Worker {
	public:
		char	getType() const override {return 'M';};
    Miner(int d) : Worker(d) {probability_of_quitting = 10; quits_after_day = 2;};
		~Miner() override = default;
};

#endif
