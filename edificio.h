#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <string>

using namespace std;

class Edificio{
    string type;
    int valor_construcao;
public:
		Edificio() : type("   ") {}
    void setType(string type);
    string getType(void) const;
    void setValorConstrucao(int valor_construcao);
    int getValorConstrucao(void) const;
};

#endif //EDIFICIO_H
