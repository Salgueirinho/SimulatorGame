#ifndef ZONA_H
#define ZONA_H

#include <string>
#include "edificio.h"

using namespace std;

class Zona {
	private:
		string zone_type;
    static	int eficiencia_mineracao;
	public:
		void setZone(string zone_type);
		string getZone(void) const;
};

class Pastagem : public Zona {
	private:
	public:
};

class	Deserto : public Zona {
	private:
	public:
};

class Floresta : public Zona {
	private:
	public:
};

class Montanha : public Zona {
	private:
	public:
};

class Pantano : public Zona {
	private:
	public:
};

class ZonaX : public Zona {
	private:
	public:
};

#endif // ZONA_H
