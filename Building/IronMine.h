#ifndef IRONMINE_H
#define IRONMINE_H

#include "Building.h"

class IronMine : public Building {
	public:
    IronMine(int day) : Building(day) {};
		std::string getType() const override {return "mnF";};
    void levelUp() override;
    int getLevel() const override {return level;};
    int sellAllResources() override;
    void work(Resources& resources, int day, int n) override;
		void work_(int number_of_miners);
		~IronMine() override = default;
	private:
		int	iron = 0;
		int	level = 1;
    int max_iron = 100;
};

#endif
