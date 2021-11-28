#ifndef ISLAND_H
#define ISLAND_H

#include "Zone.h"

class Island {
	public:
		Island(int lines, int columns);
		~Island();
		void randomizeZones(int n_zones);
		void display();
	private:
		int	rows;
		int	columns;
		Zone ***zones;
};

#endif
