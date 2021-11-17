#include <iostream>
#include <sstream>
#include "interface.h"
#include "comando.h"
#include "ilha.h"

using namespace std;

void	Interface::startSimulation(void)
{
	Interface interface;
	Comando comando;
	int	lines;
	int	columns;

	srand((unsigned) time(0));

	while (lines < 3 || 8 < lines)
	{
		cout << "Please insert the number of lines for the island grid: ";	
		lines = interface.getNumber();
		if (lines < 3 || 8 < lines)
			cout << "Please insert a value between 3 and 8." << endl;
	}
	while (columns < 3 || 16 < columns)
	{
		cout << "Please insert the number of columns for the island grid: ";	
		columns = interface.getNumber();
		if (columns < 3 || 16 < columns)
			cout << "Please insert a value between 3 and 16." << endl;
	}
	Ilha ilha(lines, columns);
	ilha.setZoneTypes();
	while (1)
	{
		ilha.displayZones();
		comando.command();
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
