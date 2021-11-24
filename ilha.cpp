#include "ilha.h"
#include "zona.h"
#include <ctime>
#include <iostream>

using namespace std;

void Ilha::setZoneTypes(void)
{
	string arr[] = {"dsr", "pas", "flr", "mnt", "pnt", "znZ"};
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			this->zonas[i][j].setZone(arr[rand() % 6]);
		}
	}
}

void Ilha::display(void) const
{
	int	n = 0;
	string buf;

	for (int i = 0; i < 16; i++)
	{
		cout << "_____";
	}
	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			cout << "|" << zonas[i][j].getZone() << " ";
		}
		cout << "|" << endl;
		for (int j = 0; j < 16; j++)
		{
			cout << "|" << zonas[i][j].getEdificio() << " ";
		}
		cout << "|" << endl;
		for (int j = 0; j < 16; j++)
		{
			buf = zonas[i][j].getTrabalhadores();
			if (buf.size() == 0)
				cout << "|" << buf << "    ";
			else if (buf.size() == 1)
				cout << "|" << buf << "   ";
			else if (buf.size() == 2)
				cout << "|" << buf << "  ";
			else if (buf.size() == 3)
				cout << "|" << buf << " ";
			else if (buf.size() == 4)
				cout << "|" << buf;
		}
		cout << "|" << endl;	
		for (int j = 0; j < 16; j++)
		{
			n = zonas[i][j].getNumberTrabalhadores();
			if (n < 10)
				cout << "|" << n << "   ";
			else if (9 < n && n < 100)
				cout << "|" << n << "  ";
		}
		cout << "|" << endl;
		for (int i = 0; i < 16; i++)
		{
			cout << "_____";
		}
		cout << "|" << endl;
	}
}

void Ilha::showInfo(void) const
{
	cout << "TEST" << endl; 
}
