#include "Zone.h"
#include "Desert.h"
#include "Pasture.h"
#include "Forest.h"
#include "Mountain.h"
#include "Swamp.h"
#include "ZoneX.h"
#include "../Building/IronMine.h"
#include "../Building/CoalMine.h"
#include "../Building/PowerPlant.h"
#include "../Building/Battery.h"
#include "../Building/Foundry.h"
#include "../Building/BuildingX.h"

std::string	Zone::getWorkers() const
{
	int	i = 0;
	std::string	temp;
	for (; i < (int) workers.size() && i < 4; i++)
		temp += workers[i]->getType();
	for (; i < 4; i++)
		temp += ' ';
	return temp;
}

int	Zone::getNumberOfWorkers() const
{
	return (int) workers.size();
}

Building	*Zone::getBuilding() const
{
	return building;
}

void	Zone::setBuilding(std::string &buildingType)
{
	if (buildingType == "mnF")
		building = new IronMine;
	else if (buildingType == "mnC")
		building = new CoalMine;
	else if (buildingType == "cen")
		building = new PowerPlant;
	else if (buildingType == "bat")
		building = new Battery;
	else if (buildingType == "fun")
		building = new Foundry;
	else
		building = new BuildingX;
}

Zone::~Zone()
{
	for (int i = 0; i < (int) workers.size(); i++)
		delete workers[i];
	if (building != 0)
		delete building;
}

Zone	*createZone(const std::string &zoneType)
{
	if (zoneType == "dsr")
		return new Desert;
	else if (zoneType == "pas")
		return new Pasture;
	else if (zoneType == "flr")
		return new Forest;
	else if (zoneType == "mnt")
		return new Mountain;
	else if (zoneType == "pnt")
		return new Swamp;
	else
		return new ZoneX;
}
