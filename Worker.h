#ifndef WORKER_H
#define WORKER_H

class Worker {
	public:
		virtual char getType() const = 0;
	private:
};

class Operator : public Worker {
	public:
		char	getType() const override {return 'O';};
	private:
};

class Lumberjack : public Worker {
	public:
		char	getType() const override {return 'L';};
	private:
};

class Miner : public Worker {
	public:
		char	getType() const override {return 'M';};
	private:
};

#endif
