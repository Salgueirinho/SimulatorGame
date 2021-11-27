#include <iostream>
#include "Island.h"
#include "utils.h"

void	startGame(void)
{
	int	lines;
	int	columns;

	cout << "Please choose the number of lines the island will take." << endl;
	lines = getNumberBetween(3, 8);
	cout << "Please choose the number of columns the island will take." << endl;
	columns = getNumberBetween(3, 16);
	Island	island(lines, columns);
	string	str;
	while (1)
	{
		island.display();
		cin >> str;
	}
}
