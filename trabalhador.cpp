//
// Created by gonca on 15/11/2021.
//

#include "trabalhador.h"

Trabalhador::Trabalhador(string type) {
	this->type = type;
}

void Trabalhador::setValorContratacao(int valor_contratacao) {
	this->valor_contratacao = valor_contratacao;
}

int Trabalhador::getValorContratacao(void) const
{
	return this->valor_contratacao;
}

string	Trabalhador::getType(void) const
{
	return type;
}
