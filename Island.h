#ifndef ISLAND_H
#define ISLAND_H

#include "Zone.h"

class Island {
	public:
		Island(int lines, int columns);
		~Island();
		void display();
	private:
		int	lines;
		int	columns;
		Zone ***zones;
};

#endif