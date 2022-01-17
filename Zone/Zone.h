#ifndef ZONE_H
#define ZONE_H

#include <vector>
#include <string>
#include <map>
#include "../Building/Building.h"
#include "../Worker/Worker.h"
#include "../Worker/Miner.h"
#include "../Worker/Lumberjack.h"
#include "../Worker/Operator.h"
#include "../Resources/Resources.h"

class Zone {
	public:

    virtual std::string getType() const = 0;
		virtual ~Zone();
    virtual void work(Resources& resources, int day) = 0;

		std::string	getWorkers() const;
		int	getNumberOfWorkers(char workers_type = ' ') const;
		Building	*getBuilding();
    void removeBuilding();
		void	setBuilding(const std::string &buildingType, int day);
    int isWorkerHere(const float id) const;
    bool isWorkerMoveAvailable(const int pos);
    void changeWorkerMovesLeft(const int pos);
    void resetWorkersMovesLeft();
    void addWorker(Worker *worker);
    Worker *removeWorker(const float id);
    void removeAllWorkers();
    void handleQuitingWorkers(const int day);

    int sellBuilding(std::map<std::string, int> prices);
private:
    Building	*building = nullptr;
    std::vector<Worker*>	workers;
};

Zone	*createZone(const std::string &zoneType);

#endif