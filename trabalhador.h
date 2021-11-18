//
// Created by gonca on 15/11/2021.
//

#ifndef TRABALHADOR_H
#define TRABALHADOR_H

#include <string>

using namespace std;
class Trabalhador {
    string type;
    int valor_contratacao;
public:
    Trabalhador(string type);
    void setValor_Contratacao(int valor_contratacao);

};

#endif //TRABALHADOR_H
