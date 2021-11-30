#ifndef LUMBERJACK_H
#define LUMBERJACK_H

class Lumberjack : public Worker {
	public:
		char	getType() const override {return 'L';};
};

#endif
