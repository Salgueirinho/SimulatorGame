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
		std::string	getWorkers() const;
		int	getNumberOfWorkers() const;
		Building	*getBuilding() const;
	private:
		std::vector<Worker*>	workers;
		Building	*building;
};

class Desert : public Zone {
	public:
		std::string getType() const override {return "dsr";};
	private:
};

class Pasture : public Zone {
	public:
		std::string getType() const override {return "pas";};
	private:
};

class Forest : public Zone {
	public:
		std::string getType() const override {return "flr";};
	private:
};

class Mountain : public Zone {
	public:
		std::string getType() const override {return "mnt";};
	private:
};

class Swamp : public Zone {
	public:
		std::string getType() const override {return "pnt";};
	private:
};

class ZoneX : public Zone{
	public:
		std::string getType() const override {return "znZ";};
	private:
};

Zone	*createNewZone(const std::string &zoneType);

#endif
