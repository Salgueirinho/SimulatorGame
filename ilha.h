#ifndef ILHA_H
#define ILHA_H

#include <string>
#include <vector>
#include "zona.h"

using namespace std;

/* 
		A lot of things still missing, like for instance
		the class Trabalhador, and others.
*/

class Ilha {
	private:
		int	linhas;
		int	colunas;
	public:
		vector<vector<Zona>> zonas;
		Ilha(int linhas, int colunas);
		void setZoneTypes(void);
		void display(void);
};

#endif // ILHA_H
