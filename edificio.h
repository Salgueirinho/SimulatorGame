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
    Edificio(string type);
    void setValor_Construcao(int valor_construcao);

};

#endif //TRABALHO_PRATICO_POO_EDIFICIO_H
