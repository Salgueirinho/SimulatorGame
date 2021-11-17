#include <iostream>
#include <sstream>
#include "interface.h"
#include "ilha.h"

using namespace std;

void	Interface::startSimulation(void)
{
	Interface interface;
	int	lines;
	int	columns;

	srand((unsigned) time(0));

	cout << "Please insert the number of lines for the island grid: ";	
	lines = interface.getNumber();
	cout << "Please insert the number of columns for the island grid: ";	
	columns = interface.getNumber();
	Ilha ilha(lines, columns);
	ilha.setZoneTypes();
	while (1)
	{
		ilha.displayZones();
		// interface.getCommand();
	}
}

int		Interface::getNumber(void)
{
	string	number_string;
	int			n = 0;
	while (n <= 0)
	{
		cin >> number_string;
		stringstream	n_stream(number_string);
		n_stream >> n;
		if (n_stream.fail())
			cout << "Please write a numeric value!" << endl;
		else
		{
			if (n <= 0)
				cout << "Please insert a positive number" << endl;
		}
	}
	return (n);
}


