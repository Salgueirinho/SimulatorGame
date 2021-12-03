#ifndef OPERATOR_H
#define OPERATOR_H

#include "Worker.h"

class Operator : public Worker {
	public:
		char	getType() const override {return 'O';};
		~Operator() override = default;
};

#endif
