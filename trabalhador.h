//
// Created by gonca on 15/11/2021.
//

#ifndef TRABALHO_PRATICO_POO_TRABALHADOR_H
#define TRABALHO_PRATICO_POO_TRABALHADOR_H

#include <string>

using namespace std;
class Trabalhador {
    string type;
    int valor_contratacao;
public:
    Trabalhador(string type);
    void setValor_Contratacao(int valor_contratacao);

};

#endif //TRABALHO_PRATICO_POO_TRABALHADOR_H
