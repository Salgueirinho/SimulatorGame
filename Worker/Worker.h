#ifndef WORKER_H
#define WORKER_H

class Worker {
	public:
		virtual char getType() const = 0;
		virtual	~Worker() = default;
	private:
		float	id;
};

#endif
