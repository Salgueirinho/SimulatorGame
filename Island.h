#ifndef ISLAND_H
#define ISLAND_H

#include "Zone.h"

class Island {
	public:
		Island(int lines, int columns);
		~Island();
		void randomizeZones();
		void displayZones();
	private:
		int	rows;
		int	columns;
		Zone ***zones;
};

#endif
