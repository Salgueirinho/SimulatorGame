#include "zona.h"

void Zona::setZone(string zone_type)
{
	this->zone_type = zone_type;
}

string	Zona::getZone(void) const
{
	return zone_type;
}
