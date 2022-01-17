#ifndef BUILDINGX_H
#define BUILDINGX_H

#include "Building.h"

class BuildingX : public Building {
	public:
		std::string getType() const override {return "edX";};
    void levelUp() override{};
    int getLevel() const override {return 0;};
    int sellAllResources() override {return 0;};
    BuildingX(int day) : Building(day) {};
		~BuildingX () override = default;
    //void work_();
		void work(Resources& resources, int day, int n) override;
};

#endif
