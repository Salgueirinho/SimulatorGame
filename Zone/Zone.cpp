#include "Zone.h"
#include "Desert.h"
#include "Pasture.h"
#include "Forest.h"
#include "Mountain.h"
#include "Swamp.h"
#include "ZoneX.h"
#include "../Building/IronMine.h"
#include "../Building/CoalMine.h"
#include "../Building/PowerPlant.h"
#include "../Building/Battery.h"
#include "../Building/Foundry.h"
#include "../Building/BuildingX.h"
#include "../Building/Sawmill.h"
#include <iostream>


std::string	Zone::getWorkers() const
{
	int	i = 0;
	std::string	temp;
	for (; i < (int) workers.size() && i < 4; i++)
		temp += workers[i]->getType();
	for (; i < 4; i++)
		temp += ' ';
	return temp;
}

int	Zone::getNumberOfWorkers(char workers_type) const
{
  if(workers_type == ' ')
	  return (int) workers.size();
  else
  {
    int n = 0;
    for (auto worker : workers)
    {
      if (worker->getType() == workers_type)
        n++;
    }
    return n;
  }
}

Building	*Zone::getBuilding()
{
	return building;
}

void Zone::removeBuilding()
{
  delete building;
  building = nullptr;
}

void	Zone::setBuilding(const std::string &buildingType, int day)
{
    if (buildingType == "mnF")
      building = new IronMine(day);
    else if (buildingType == "mnC")
      building = new CoalMine(day);
    else if (buildingType == "cen")
      building = new PowerPlant(day);
    else if (buildingType == "bat")
      building = new Battery(day);
    else if (buildingType == "fun")
      building = new Foundry(day);
    else if (buildingType == "ser")
      building = new Sawmill(day);
    else
      building = new BuildingX(day);
}

Zone::~Zone()
{
	for (auto & worker : workers)
		delete worker;
	delete building;
}

Zone	*createZone(const std::string &zoneType)
{
	if (zoneType == "dsr")
		return new Desert;
	else if (zoneType == "pas")
		return new Pasture;
	else if (zoneType == "flr")
		return new Forest;
	else if (zoneType == "mnt")
		return new Mountain;
	else if (zoneType == "pnt")
		return new Swamp;
	else
		return new ZoneX;
}

int Zone::isWorkerHere(const float id) const
{
  int pos = 0;
  for (auto worker : workers)
  {
    if (worker->getID() == id)
    {
      return pos;
    }
    pos++;
  }
  return -1;
}

void Zone::addWorker(Worker *worker)
{
  this->workers.push_back(worker);
}

Worker* Zone::removeWorker(const float id)
{
  Worker *temp;
  for (int i = 0; i < (int)workers.size(); i++)
  {
    if (workers[i]->getID() == id)
    {
      temp = workers[i];
      this->workers.erase(workers.begin() + i);
      return temp;
    }
  }
  return nullptr;
}
void Zone::removeAllWorkers()
{
  for (auto worker:workers)
  {
    delete worker;
  }
  workers.clear();
}
void Zone::handleQuitingWorkers(const int day)
{
  int worker_first_day;
  int zone_effect = 0;

  if (this->getType() == "mnt")
  {
    zone_effect = 5;
  }

  for(auto worker: workers)
  {
    worker_first_day = worker->getHiringDay();
    if(worker->getType() == 'O' && day - worker_first_day >= 10)
    {
      if(rand() % 101 <= zone_effect + worker->getProbabilityOfQuiting())
      {
        std::cout << "Operator quitting" << std::endl;
        delete removeWorker(worker->getID());
        break;
      }
    }
    if(worker->getType() == 'M' && day - worker_first_day >= 2)
    {
      if(rand() % 101 <= zone_effect + worker->getProbabilityOfQuiting())
      {
        std::cout << "Miner quitting" << std::endl;
        delete removeWorker(worker->getID());
        break;
      }
    }
    if(worker->getType() == 'L' && getType() == "mnt")
    {
      if(rand() % 101 <= zone_effect)
      {
        std::cout << "Lumberjack quitting" << std::endl;
        delete removeWorker(worker->getID());
        break;
      }
    }
  }
}

bool Zone::isWorkerMoveAvailable(const int pos)
{
  if (this->getNumberOfWorkers() >= 1 && workers[pos]->getMovesLeft() >= 1)
  {
    return true;
  }
  else
  {
    return false;
  }
}
void Zone::changeWorkerMovesLeft(const int pos)
{
  if (this->getNumberOfWorkers() >= 1 && pos >= 0)
  {
    workers[pos]->changeMovesLeft();
  }
}

void Zone::resetWorkersMovesLeft()
{
  for (auto worker:workers)
  {
    worker->resetMovesLeft();
  }
}

int Zone::sellBuilding(std::map<std::string, int> prices)
{
  int sell_price=0;
  if (building != nullptr)
  {
    sell_price = prices[building->getType()];
    sell_price += building->sellAllResources();
    removeBuilding();
  }
  return sell_price;
}
