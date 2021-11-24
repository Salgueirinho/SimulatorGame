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
		Zona zonas[8][16];
		void setZoneTypes(void);
		void display(void) const;
		void showInfo(void) const;
};

#endif // ILHA_H
