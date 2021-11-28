#include "Island.h"
#include <typeinfo>
#include <iostream>
#include <algorithm>
#include <random>

Island::Island(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	this->zones = new Zone**[rows];
	for (int i = 0; i < rows; i++)
		zones[i] = new Zone*[columns];
	randomizeZones(rows * columns);
}

void	Island::randomizeZones(int n_zones)
{
	std::vector<Zone*> temp;
	std::random_device rd;
	std::mt19937 g(rd());

	while ((int) temp.size() < n_zones)
	{
		temp.push_back(new Desert[1]);
		temp.push_back(new Pasture[1]);
		temp.push_back(new Forest[1]);
		temp.push_back(new Mountain[1]);
		temp.push_back(new Swamp[1]);
		temp.push_back(new ZoneX[1]);
	}
	for (int i = n_zones; i < (int) temp.size(); i++)
	{
		delete [] temp[i];
		temp.erase(temp.begin() + i);
	}
	std::shuffle(temp.begin(), temp.end(), g);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			zones[i][j] = temp[i * columns + j];
	temp.clear();
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

void	Island::display()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			std::cout << zones[i][j]->getType() << " ";
		std::cout << std::endl;
	}
}
