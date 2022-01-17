#ifndef BATTERY_H
#define BATTERY_H

#include "Building.h"

class Battery : public Building {
	public:
		std::string getType() const override {return "bat";};
    void levelUp() override;
    int getLevel() const override {return level;};
    int sellAllResources() override;
    void work(Resources& resources, int day, int n) override;
		void work_(const int energy);
    Battery(int day) : Building(day) {};
		~Battery () override = default;
	private:
		int	electricity = 0;
    int level = 1;
    int max_electricity = 100;
};

#endif
