#include "Zone.h"

Zone	*createNewZone(std::string zoneType)
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
