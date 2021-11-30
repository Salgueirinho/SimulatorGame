#include "Zone.h"

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

Zone	*createNewZone(const std::string &zoneType)
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
