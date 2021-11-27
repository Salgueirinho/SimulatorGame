#ifndef ZONE_H
#define ZONE_H

#include <vector>
#include "Building.h"
#include "Worker.h"

using namespace	std;

class Zone {
	public:
	private:
		vector<Worker>	workers;
		Building	*building;
};

class Desert : public Zone {

};

class Pasture : public Zone {

};

class Forest : public Zone {

};

class Mountain : public Zone {

};

class Swamp : public Zone {

};

class ZoneX : public Zone{

};

#endif
