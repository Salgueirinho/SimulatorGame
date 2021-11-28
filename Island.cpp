#include "Island.h"
#include <typeinfo>
#include <iostream>

Island::Island(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	this->zones = new Zone**[rows];
	for (int i = 0; i < rows; i++)
	{
		zones[i] = new Zone*[columns];
		for (int j = 0; j < columns; j++)
			zones[i][j] = new Forest[1];
	}
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

void Island::display()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			std::cout << zones[i][j]->getType() << " ";
		std::cout << std::endl;
	}
}
