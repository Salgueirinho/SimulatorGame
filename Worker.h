#ifndef WORKER_H
#define WORKER_H

class Worker {
	public:
		virtual std::string getType() const = 0;
	private:
};

class Operator : public Worker {
	public:
		std::string getType() const override {return "Operator";};
	private:
};

class Lumberjack : public Worker {
	public:
		std::string getType() const override {return "Lumberjack";};
	private:
};

class Miner : public Worker {
	public:
		std::string getType() const override {return "Miner";};
	private:
};

#endif
