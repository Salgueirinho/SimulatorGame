#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include "Resources/Resources.h"

class Building {
	public:
    int built_day;
    bool	active = false;

		virtual std::string getType() const = 0;
    virtual void levelUp() = 0;
    virtual int getLevel() const = 0;
    virtual int sellAllResources() = 0;
    virtual void work(Resources& resources, int day, int n) = 0;
		Building(const int day);
    virtual	~Building() = default;
		void	activate();
		void	deactivate();
	private:

};

#endif
