#ifndef SAWMILL_H
#define SAWMILL_H

#include "Building.h"

class Sawmill : public Building {
public:
    Sawmill(int day) : Building(day) {};
    ~Sawmill () override = default;
    std::string getType() const override {return "ser";};
    void work(Resources& resources, int day, int n) override;
    void work_(int &wood, int number_of_operators) ;
    int getLevel() const override {return 0;};
    int sellAllResources() override;
    void levelUp() override {};

private:
    int wood_planks = 0;
};


#endif //SAWMILL_H
