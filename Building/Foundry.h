#ifndef FOUNDRY_H
#define FOUNDRY_H

#include "Building.h"

class Foundry : public Building {
	public:
		std::string getType() const override {return "fun";};
    void levelUp() override {};
    int getLevel() const override {return 0;};
    int sellAllResources() override;
    void work(Resources& resources, int day, int n) override;
		void work_(int &coal, int &iron, int valid_neighbors, int number_of_operators);
    Foundry(int day) : Building(day) {};
		~Foundry() override = default;
	private:
		int	steel = 0;
};

#endif
