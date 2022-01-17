//#include <typeinfo>
#include <algorithm>
#include <random>
#include <sstream>
#include <iostream>
#include "Island.h"

Island::Island(const int rows, const int columns)
{
	this->rows = rows;
	this->columns = columns;
	zones = new Zone**[rows];
	for (int i = 0; i < rows; i++)
		zones[i] = new Zone*[columns];
	randomizeZones();
}

void	Island::randomizeZones()
{
	std::vector<Zone*> temp;
	std::string zoneTypes[] = {"dsr", "pas", "flr", "mnt", "pnt", "znZ"};
	while ((int) temp.size() < rows * columns)
		temp.push_back(createZone(zoneTypes[temp.size() % 6]));
	std::shuffle(temp.begin(), temp.end(), std::random_device());
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			zones[i][j] = temp[i * columns + j];
}

Island::~Island()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			delete zones[i][j];
		delete [] zones[i];
	}
	delete [] zones;
}

int Island::getNumberOfWorkers() const
{
  int number_of_workers = 0;
  for(int i=0; i<rows; i++)
  {
    for(int j=0; j<columns; j++)
    {
      number_of_workers += this->zones[i][j]->getNumberOfWorkers();
    }
  }
  return number_of_workers;
}
std::string	Island::getAsString() const
{
	std::ostringstream	oss;
	int	j;
	for (int i = 0; i < rows; i++)
	{
		oss << std::endl << "_";
		for (j = 0; j < columns; j++)
			oss << "_____";
		oss << std::endl << "|";
		for (j = 0; j < columns; j++)
			oss << zones[i][j]->getType() << " |";
		oss << std::endl << "|";
		for (j = 0; j < columns; j++)
		{
			Building *building;
			if ((building = zones[i][j]->getBuilding()) == nullptr)
				oss << "    |";
			else
				oss << building->getType() << " |";
		}
		oss << std::endl << "|";
		for (j = 0; j < columns; j++)
			oss << zones[i][j]->getWorkers() << "|";
		oss << std::endl << "|";
		for (j = 0; j < columns; j++)
		{
			int n = zones[i][j]->getNumberOfWorkers();
			if (n <= 9)
				oss << n << "   |";
			else if (n <= 99)
				oss << n << "  |";
			else if (n <= 999)
				oss << n << " |";
			else
				oss << "999+|";
		}
	}
	oss << std::endl << "_";
	for (j = 0; j < columns; j++)
		oss << "_____";
	oss << std::endl;
	return oss.str();
}

std::string Island::getAllInfoAsString() const
{
    //Incomplete
    // Missing number of all buildings and Resources
    std::ostringstream oss;

    int number_of_workers = 0;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            number_of_workers += this->zones[i][j]->getNumberOfWorkers();
            oss << this->getZoneInfoAsString(i,j);
        }
    }

    oss << "Total Number of Workers: " << number_of_workers << std::endl;
    return oss.str();
}

std::string Island::getZoneInfoAsString(int row, int column) const {
    std::ostringstream oss;

    oss << "Row: " << row << "  Column: " << column << std::endl;
    oss << "Zone Type: " << zones[row][column]->getType() << std::endl;
    if (zones[row][column]->getBuilding() != nullptr)
    {
        oss << "Building: " << zones[row][column]->getBuilding()->getType() << std::endl;
        if (zones[row][column]->getBuilding()->active)
            oss << "Active: True" << std::endl;
        else
            oss << "Active: False" << std::endl;
    }
    else
        oss << "Building: None" << std::endl;
    oss << "Number of Workers: " << zones[row][column]->getNumberOfWorkers() << std::endl;
    return oss.str();
}

std::vector<std::vector<int>> Island::getSpecificZone(std::string zone_type) const
{
  std::vector<std::vector<int>> pastures;
  std::vector<int> coords;
  for (int i = 0 ; i < getRows(); i++)
  {
    for (int j = 0 ; j < getColumns(); j++)
    {
      if (zones[i][j]->getType() == zone_type)
      {
        coords.push_back(i);
        coords.push_back(j);
        pastures.push_back(coords);
        coords.clear();
      }
    }
  }
  return pastures;
}

void Island::hire(const std::string &worker_type, int d)
{
  Worker *new_worker = nullptr;
  std::vector<std::vector<int>> pastures = getSpecificZone("pas");
  int r = rand() % pastures.size() ;

  if (worker_type == "min")
  {
    new_worker = new Miner(d);
  }
  else if (worker_type == "ope")
  {
    new_worker = new Operator(d);
  }
  else if (worker_type == "len")
  {
    new_worker = new Lumberjack(d);
  }
  this->zones[pastures[r][0]][pastures[r][1]]->addWorker(new_worker);
}

bool Island::move(const float id, const int row, const int column)
{
  int pos;
  Worker *temp = nullptr;
  for (int i = 0 ; i < getRows(); i++)
  {
    for (int j = 0 ; j < getColumns(); j++)
    {
      if ((pos = zones[i][j]->isWorkerHere(id)) >= 0)
      {
      if (zones[i][j]->isWorkerMoveAvailable(pos))
        {
          std::cout << "Worker is available" << std::endl;
          zones[i][j]->changeWorkerMovesLeft(pos);
          temp = zones[i][j]->removeWorker(id);
          break;
        }
      }
    }
  }
  if(temp)
  {
    zones[row][column]->addWorker(temp);
    return true;
  }
  return false;
}

void Island::killWorkerID(const float id)
{
  Worker *temp;
  for (int i = 0 ; i < getRows(); i++)
  {
    for (int j = 0 ; j < getColumns(); j++)
    {
      if ((zones[i][j]->isWorkerHere(id)) >= 0)
      {
        temp = zones[i][j]->removeWorker(id);
        delete temp;
        break;
      }
    }
  }
}


void Island::simulateDusk(Resources& resources, int day)
{
  for (int i = 0 ; i < getRows(); i++)
  {
    for (int j = 0; j < getColumns(); j++)
    {
      std::cout << "linha: " << i << " coluna: " << j << std::endl;
      zones[i][j]->work(resources, day);
    }
  }
}
