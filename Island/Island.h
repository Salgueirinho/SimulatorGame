#ifndef ISLAND_H
#define ISLAND_H

#include "../Zone/Zone.h"

class Island {
  public:
    Zone ***zones;

    Island(int rows, int columns);
    ~Island();
    void randomizeZones();
    int getNumberOfWorkers()const;
    std::string     getAsString() const;
    std::string     getAllInfoAsString() const;
    std::string     getZoneInfoAsString(int row, int column) const;
    std::vector<std::vector<int>> getSpecificZone(std::string zone_type) const;
    void hire(const std::string &worker_type, int d);
    bool move(const float id, const int row, const int column);
    void killWorkerID(const float id);
    void simulateDusk(Resources& resources, int day);
    int	getRows() const {return rows;};
    int	getColumns() const {return columns;};
	private:
		int	rows;
		int	columns;
};

#endif
