#include "edificio.h"

void Edificio::setType(string type) {
	this->type = type;
}

void Edificio::setValorConstrucao(int valor_construcao) {
	this->valor_construcao = valor_construcao;
}

int Edificio::getValorConstrucao(void) const
{
	return this->valor_construcao;
}
string Edificio::getType(void) const
{
	return this->type;
}
