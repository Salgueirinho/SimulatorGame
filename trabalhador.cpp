//
// Created by gonca on 15/11/2021.
//

#include "trabalhador.h"

Trabalhador::Trabalhador(string type) {
    this->type = type;
}

void Trabalhador::setValor_Contratacao(int valor_contratacao) {
    this->valor_contratacao = valor_contratacao;
}
