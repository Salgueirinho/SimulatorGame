#ifndef MINER_H
#define MINER_H

#include "Worker.h"

class Miner : public Worker {
	public:
		char	getType() const override {return 'M';};
};

#endif
