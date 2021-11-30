#ifndef MINER_H
#define MINER_H

class Miner : public Worker {
	public:
		char	getType() const override {return 'M';};
};

#endif
