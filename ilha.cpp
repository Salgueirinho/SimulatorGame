#include "ilha.h"
#include "zona.h"
#include <ctime>
#include <iostream>
#include <sstream>

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

string Ilha::getInfoAsString(int x, int y) const
{
    ostringstream oss;
    oss << "Tipo de Zona: " << this->zonas[x][y].getZone() << endl;
    oss << "Edificio: " << this->zonas[x][y].getEdificio() << endl;
    oss << "Quantidade de trabalhadores: " << this->zonas[x][y].getNumberTrabalhadores() << endl;

    return oss.str();
}
string Ilha::getAllInfoAsString(void) const
{
    ostringstream oss;
    int quantidade_trabalhadores = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            quantidade_trabalhadores += this->zonas[i][j].getNumberTrabalhadores();
        }
    }
    oss << "Numero de trabalhadores em toda a ilha: " << quantidade_trabalhadores << endl;

    return oss.str();
}


