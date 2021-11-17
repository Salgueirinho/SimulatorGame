#include <iostream>
#include <sstream>
#include <algorithm>
#include "interface.h"
#include "ilha.h"

using namespace std;

void	Interface::startSimulation(void)
{
	Interface interface;
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
		interface.command();
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

void	Interface::command(void)
{
	string	command;
	vector<string> commands {"exec", "cons", "ligia", "des", "move", "vende", "cont", "list", "next", "save", "load", "apaga", "config", "debcash", "debed", "debkill"};
	while (!count(commands.begin(), commands.end(), command))
	{
		cout << "command: ";
		cin >> command;
		if (!count(commands.begin(), commands.end(), command))
			cout << "Please insert a valid command" << endl;
	}
}
