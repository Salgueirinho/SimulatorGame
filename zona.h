#ifndef ZONA_H
#define ZONA_H

#include <string>
#include "edificio.h"

using namespace std;

class Zona {
	private:
		string zone_type;
    int eficiencia_mineracao;
	public:
		void setZone(string zone_type);
		string getZone(void) const;
	/*
		Zona(string zone_type);

		Have to leave this default constructor because
		otherwise I cannot create a vector of vectors of this type.
	*/
};

#endif // ZONA_H
