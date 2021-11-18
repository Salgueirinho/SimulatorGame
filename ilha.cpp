#include "ilha.h"
#include "zona.h"
#include <ctime>
#include <iostream>

using namespace std;

Ilha::Ilha(int linhas, int colunas)
{
	this->zonas.resize(colunas);

	for (int i = 0; i < colunas; i++)
	{
		zonas[i].resize(linhas);
	}
}

void Ilha::setZoneTypes(void)
{
	string arr[] = {"Deserto", "Pastagem", "Floresta", "Montanha", "Pantano", "Zona-X"};
	for (int i = 0; i < this->zonas.size(); i++)
	{
		for (int j = 0; j < this->zonas[i].size(); j++)
		{
			this->zonas[i][j].setZone(arr[rand() % 6]);
		}
	}
}

void Ilha::display(void)
{
	for (int i = 0; i < this->zonas.size(); i++)
	{
		for (int j = 0; j < this->zonas[i].size(); j++)
		{
			cout << zonas[i][j].getZone() << " ";
		}
		cout << endl;
	}
}
