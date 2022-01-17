#ifndef WORKER_H
#define WORKER_H

#include <cmath>
#include "../utils/utils.h"

class Worker {
	public:
		virtual char getType() const = 0;
    Worker(int d);
		virtual	~Worker() = default;
    float getID() const {return id;};
    int getHiringDay() const;
    int getProbabilityOfQuiting()const {return probability_of_quitting;};
    int getMovesLeft()const;
    void resetMovesLeft() {moves_left = 1;};
    void changeMovesLeft();
	protected:
    int _n;
		float	id;
    int hiring_day;
    int probability_of_quitting;
    int quits_after_day;
    int moves_left = 1;
};

#endif
