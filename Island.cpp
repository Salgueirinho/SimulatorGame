#include "Island.h"
#include <typeinfo>
#include <iostream>

Island::Island(int lines, int columns)
{
	this->lines = lines;
	this->columns = columns;
	this->zones = new Zone**[lines];
	for (int i = 0; i < lines; i++)
		zones[i] = new Zone*[columns];
}

Island::~Island()
{
	for (int i = 0; i < lines; i++)
		delete [] zones[i];
	delete [] zones;
}

void Island::display()
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << typeid(zones[i][j]).name() << " ";
		}
		cout << endl;
	}
}
