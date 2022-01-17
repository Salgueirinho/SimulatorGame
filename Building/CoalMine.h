#ifndef COALMINE_H
#define COALMINE_H

#include "Building.h"

class CoalMine : public Building {
	public:
		std::string getType() const override {return "mnC";};
    void work(Resources& resources, int day, int n) override;
    void work_(int number_of_miners);
    void levelUp() override;
    int getLevel() const override {return level;};
    int sellAllResources() override;
    CoalMine(int day) : Building(day) {};
    ~CoalMine() override = default;
	private:
    int coal = 0;
		int	level = 1;
    int max_coal = 100;
};

#endif
