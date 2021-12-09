#ifndef ISLAND_H
#define ISLAND_H

#include "../Zone/Zone.h"

class Island {
	public:
		Island(int rows, int columns);
		~Island();
		void randomizeZones();
		std::string	getAsString() const;
		int	getRows() const {return rows;}
		int	getColumns() const {return columns;}
	private:
		Zone ***zones;
		int	rows;
		int	columns;
};

#endif
