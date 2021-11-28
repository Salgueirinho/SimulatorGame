#ifndef ZONE_H
#define ZONE_H

#include <vector>
#include <string>
#include "Building.h"
#include "Worker.h"

class Zone {
	public:
		virtual std::string getType(void) const = 0;
	private:
		std::vector<Worker>	workers;
		Building	*building;
};

class Desert : public Zone {
	public:
		std::string getType(void) const override {return "Desert";};
	private:
};

class Pasture : public Zone {
	public:
		std::string getType(void) const override {return "Pasture";};
	private:
};

class Forest : public Zone {
	public:
		std::string getType(void) const override {return "Forest";};
	private:
};

class Mountain : public Zone {
	public:
		std::string getType(void) const override {return "Mountain";};
	private:
};

class Swamp : public Zone {
	public:
		std::string getType(void) const override {return "Swamp";};
	private:
};

class ZoneX : public Zone{
	public:
		std::string getType(void) const override {return "ZoneX";};
	private:
};

#endif
