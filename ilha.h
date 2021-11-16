#ifndef ILHA_H
#define ILHA_H

#include <string>
#include <vector>

using namespace std;

/* 
		A lot of things still missing, like for instance
		the class Trabalhador, and others.
*/

class Ilha {
	private:
		int	linhas;
		int	colunas;
		/*
			vector<vector<Zona>> zonas;

			Can't implement this yet.
		*/
		vector<vector<string>> zonas;
	public:
		Ilha(int linhas, int colunas);
};

#endif // ILHA_H
