#ifndef OPERATOR_H
#define OPERATOR_H

#include "Worker.h"

class Operator : public Worker {
	public:
		char	getType() const override {return 'O';};
    Operator(int d) : Worker(d) {probability_of_quitting = 5; quits_after_day = 10;};
		~Operator() override = default;
};

#endif
