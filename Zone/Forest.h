#ifndef FOREST_H
#define FOREST_H

#include "Zone.h"

class Forest : public Zone {
	public:
		std::string getType() const override {return "flr";};
    int getNumberOfTrees() const  {return trees;};
    void growTrees(int day);
    void handleBuildingExistence();
    void work(Resources& resources, int day) override;

    Forest();
		~Forest() override = default;
	private:
    int   wood;
		int	trees;
};

#endif
