#ifndef OPERATOR_H
#define OPERATOR_H

class Operator : public Worker {
	public:
		char	getType() const override {return 'O';};
};

#endif
