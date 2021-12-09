#ifndef ISLAND_H
#define ISLAND_H

#include "../Zone/Zone.h"

class Island {
	public:
		Island(int rows, int columns);
		~Island();
		void randomizeZones();
		std::string	getAsString() const;
	private:
		int	rows;
		int	columns;
		Zone ***zones;
};

#endif
