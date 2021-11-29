#ifndef ZONE_H
#define ZONE_H

#include <vector>
#include <string>
#include "Building.h"
#include "Worker.h"

class Zone {
	public:
		virtual std::string getType() const = 0;
		virtual ~Zone() = default;
	private:
		std::vector<Worker*>	workers;
		Building	*building;
};

class Desert : public Zone {
	public:
		std::string getType() const override {return "Desert";};
	private:
};

class Pasture : public Zone {
	public:
		std::string getType() const override {return "Pasture";};
	private:
};

class Forest : public Zone {
	public:
		std::string getType() const override {return "Forest";};
	private:
};

class Mountain : public Zone {
	public:
		std::string getType() const override {return "Mountain";};
	private:
};

class Swamp : public Zone {
	public:
		std::string getType() const override {return "Swamp";};
	private:
};

class ZoneX : public Zone{
	public:
		std::string getType() const override {return "ZoneX";};
	private:
};

Zone	*createNewZone(const std::string &zoneType);

#endif
