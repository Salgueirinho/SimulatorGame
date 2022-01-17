#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "Building.h"

class PowerPlant : public Building {
	public:
		std::string getType() const override {return "cen";};
    void work(Resources& resources, int day, int n) override;
    void work_(int number_of_operators, int &wood) ;
    void levelUp() override {};
    int getLevel() const override {return 0;};
    int sellAllResources() override;
    PowerPlant(int day) : Building(day) {};
    ~PowerPlant() override = default;
	private:
		int	coal = 0;
    int max_coal = 100;
};

#endif
