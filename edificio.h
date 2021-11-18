//
// Created by gonca on 15/11/2021.
//

#ifndef TRABALHO_PRATICO_POO_EDIFICIO_H
#define TRABALHO_PRATICO_POO_EDIFICIO_H

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

#endif //TRABALHO_PRATICO_POO_EDIFICIO_H
