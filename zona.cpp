#include <sstream>
#include "zona.h"
#include "edificio.h"

void Zona::setZone(string zone_type)
{
	this->zone_type = zone_type;
}

void Zona::setEdificio(string edificio_type)
{
	this->edificio.setType(edificio_type);
}

string	Zona::getZone(void) const
{
	return zone_type;
}

string	Zona::getEdificio(void) const
{
	return edificio.getType();
}

int	Zona::getNumberTrabalhadores(void) const
{
	return trabalhadores.size();
}

string	Zona::getTrabalhadores(void) const
{
	stringstream	ss;
	int	n_trabalhadores = getNumberTrabalhadores();
	for (int i = 0; i < min(n_trabalhadores, 4); i++)
	{
		ss << trabalhadores[i].getType()[0];
	}
	return ss.str();
}

void Zona::setTrabalhador(Trabalhador worker)
{
	this->trabalhadores.push_back(worker);
}
