#include "Zone.h"

std::vector<std::string>	Zone::getWorkers() const
{
	std::vector<std::string>	workersAsString;
	for (int i = 0; i < (int) workers.size(); i++)
		workersAsString.push_back(workers[i]->getType());
	return (workersAsString);
}

int	Zone::getNumberOfWorkers() const
{
	return ((int) workers.size());
}

Building	*Zone::getBuilding() const
{
	return (building);
}

Zone	*createNewZone(const std::string &zoneType)
{
	if (zoneType == "Desert")
		return (new Desert[1]);
	else if (zoneType == "Pasture")
		return (new Pasture[1]);
	else if (zoneType == "Forest")
		return (new Forest[1]);
	else if (zoneType == "Mountain")
		return (new Mountain[1]);
	else if (zoneType == "Swamp")
		return (new Swamp[1]);
	else
		return (new ZoneX[1]);
}
