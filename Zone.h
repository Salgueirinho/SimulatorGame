#ifndef ZONE_H
#define ZONE_H

#include <vector>
#include <string>
#include "Building.h"
#include "Worker.h"

class Zone {
	public:
		virtual std::string getType() const = 0;
		virtual ~Zone();
		std::string	getWorkers() const;
		int	getNumberOfWorkers() const;
		Building	*getBuilding() const;
		void	setBuilding(std::string &buildingType);
	private:
		std::vector<Worker*>	workers;
		Building	*building;
};

Zone	*createZone(const std::string &zoneType);

#endif
