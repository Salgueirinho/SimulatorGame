#ifndef ISLAND_H
#define ISLAND_H

#include "Zone.h"

class Island {
	public:
		Island(int lines, int columns);
		~Island();
		void randomizeZones();
		void displayZones() const;
	private:
		int	rows;
		int	columns;
		Zone ***zones;
};

#endif
