#ifndef ZONA_H
#define ZONA_H

#include <string>
#include <vector>
#include "edificio.h"
#include "trabalhador.h"

using namespace std;

class Zona {
	private:
		string zone_type;
		Edificio edificio;
    static	int eficiencia_mineracao;
		vector<Trabalhador> trabalhadores;
	public:
		void setZone(string zone_type);
		void setEdificio(string edificio_type);
		string	getZone(void) const;
		string	getEdificio(void) const;
		int	getNumberTrabalhadores(void) const;
		string	getTrabalhadores(void) const;
        void setTrabalhador(Trabalhador worker);
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
