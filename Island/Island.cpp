#include <typeinfo>
#include <algorithm>
#include <random>
#include <sstream>
#include "Island.h"
#include "../utils/utils.h"

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
