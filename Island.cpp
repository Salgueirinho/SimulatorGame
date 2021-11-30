#include <typeinfo>
#include <iostream>
#include <algorithm>
#include <random>
#include "Island.h"

Island::Island(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	this->zones = new Zone**[rows];
	for (int i = 0; i < rows; i++)
		zones[i] = new Zone*[columns];
	randomizeZones();
}

void	Island::randomizeZones()
{
	std::vector<Zone*> temp;
	std::string zoneTypes[] = {"dsr", "pas", "flr", "mnt", "pnt", "znZ"};
	while ((int) temp.size() < rows * columns)
		temp.push_back(createNewZone(zoneTypes[temp.size() % 6]));
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
			delete [] zones[i][j];
		delete [] zones[i];
	}
	delete [] zones;
}

void	Island::displayZones() const
{
	std::cout << std::endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			std::cout << zones[i][j]->getType() << " ";
		std::cout << std::endl;
		for (int j = 0; j < columns; j++)
		{
			Building *building;
			if ((building = zones[i][j]->getBuilding()) == 0)
				std::cout << "    ";
			else
				std::cout << building->getType() << " ";
		}
		std::cout << std::endl;
		for (int j = 0; j < columns; j++)
			std::cout << zones[i][j]->getWorkers() << " ";
		std::cout << std::endl;
		for (int j = 0; j < columns; j++)
		{
			int	n;
			if ((n = zones[i][j]->getNumberOfWorkers()) < 10)
				std::cout << n << "   ";
			else if (n < 100)
				std::cout << n << "  ";
			else if (n < 1000)
				std::cout << n << " ";
			else
				std::cout << "999+";
		}
		std::cout << std::endl;
	}
}
