#ifndef FOREST_H
#define FOREST_H

#include "Zone.h"

class Forest : public Zone {
	public:
		std::string getType() const override {return "flr";};
		Forest();
		~Forest() override = default;
	private:
		int	trees;
};

#endif
