#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <string>

using namespace std;

class Edificio{
    string type;
    int valor_construcao;
public:
    void setType(string type);
    void setValorConstrucao(int valor_construcao);
    int getValorConstrucao(void) const;
    string getType(void) const;


};

#endif //EDIFICIO_H
