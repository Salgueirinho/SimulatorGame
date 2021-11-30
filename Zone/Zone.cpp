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
		temp[i] = workers[i]->getType();
	for (; i < 4; i++)
		temp[i] = ' ';
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
		building = new IronMine[1];
	else if (buildingType == "mnC")
		building = new CoalMine[1];
	else if (buildingType == "cen")
		building = new PowerPlant[1];
	else if (buildingType == "bat")
		building = new Battery[1];
	else if (buildingType == "fun")
		building = new Foundry[1];
	else
		building = new BuildingX[1];
}

Zone::~Zone()
{
	for (auto worker : workers)
		delete [] worker;
	delete [] building;
}

Zone	*createZone(const std::string &zoneType)
{
	if (zoneType == "dsr")
		return new Desert[1];
	else if (zoneType == "pas")
		return new Pasture[1];
	else if (zoneType == "flr")
		return new Forest[1];
	else if (zoneType == "mnt")
		return new Mountain[1];
	else if (zoneType == "pnt")
		return new Swamp[1];
	else
		return new ZoneX[1];
}
