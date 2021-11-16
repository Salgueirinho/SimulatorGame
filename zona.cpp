#include "zona.h"

void Zona::setZone(string zone_type)
{
	this->zone_type = zone_type;
}

string Zona::getZone(void)
{
	return this->zone_type;
}
