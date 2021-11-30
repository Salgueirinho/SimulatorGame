#ifndef WORKER_H
#define WORKER_H

class Worker {
	public:
		virtual char getType() const = 0;
};

class Operator : public Worker {
	public:
		char	getType() const override {return 'O';};
};

class Lumberjack : public Worker {
	public:
		char	getType() const override {return 'L';};
};

class Miner : public Worker {
	public:
		char	getType() const override {return 'M';};
};

#endif
