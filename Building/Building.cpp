#include "Building.h"

Building::Building(const int day)
{
  built_day = day;
}

void	Building::activate()
{
	active = true;
}

void	Building::deactivate()
{
	active = false;
}

