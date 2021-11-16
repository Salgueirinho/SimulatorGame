#include "ilha.h"
#include "zona.h"

using namespace std;

Ilha::Ilha(int linhas, int colunas)
{
	vector<vector<Zona>> zonas(colunas);
	for (int i = 0; i < colunas; i++)
	{
		zonas[i].resize(linhas);
	}
}
