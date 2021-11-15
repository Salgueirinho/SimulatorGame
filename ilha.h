#ifndef ILHA_H
#define ILHA_H

#include <string>
#include <vector>

using namespace std;

/* 
		A lot of things still missing, like for instance
		the class Trabalhador, and others.
*/

class Zona {
	private:
		string zone_type;
	public:
		Zona(string zone_type);
};

class Ilha {
	private:
		int	linhas;
		int	colunas;
		vector<vector<Zona>> zonas;
	public:
		Ilha(int linhas, int colunas);
};

#endif // ILHA_H
