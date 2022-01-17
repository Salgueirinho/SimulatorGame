#ifndef LUMBERJACK_H
#define LUMBERJACK_H

#include "Worker.h"

class Lumberjack : public Worker {
	public:
		char	getType() const override {return 'L';};
    Lumberjack(int d) : Worker(d) {probability_of_quitting = 0; quits_after_day = -1;};
		~Lumberjack() override = default;
};

#endif
