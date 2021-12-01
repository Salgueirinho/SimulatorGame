#ifndef LUMBERJACK_H
#define LUMBERJACK_H

#include "Worker.h"

class Lumberjack : public Worker {
	public:
		char	getType() const override {return 'L';};
		~Lumberjack() override {};
};

#endif
