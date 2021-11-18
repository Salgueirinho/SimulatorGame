#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include "comando.h"

using namespace std;

class	Interface
{
	private:
		vector<Command> commands = {{"exec", {"<nomeFicheiro>"}, "Executa um conjunto de comandos existentes em nomeFicheiro. Esse ficheiro tem os comandos, um por cada linha, segundo a mesma sintaxe como quando são escritos diretamente no teclado."},
									{"cons", {"<tipo>", "<linha>", "<coluna>"}, "Constrói um edifício de um dado tipo na zona posicionada na linha e coluna. Nesta zona não poderá haver outro edifício e as condições necessária para a construção do tipo de edifício deverão ser observadas na altura de execução do comando. Tipo = minaf | minac | central | bat | fund | edx (abreviaturas baseadas nos nomes dos recursos em minúsculas e sem letras acentuadas)."}, 
									{"liga", {"<linha>", "<coluna>"}, "Liga o edifício (caso exista) que está construído na zona posicionada na linha e coluna."},
									{"des", {"<linha>", "<coluna>"}, "Desliga o edifício (caso exista) que está construído na zona posicionada na linha e coluna."},
									{"move", {"<id>", "<linha>", "<coluna>"}, "Move o trabalhador com o identificador id para a zona posicionada na linha e coluna."},
									{"vende", {"<tipo>", "<quanto>"}, "Vende recursos de um dado tipo e de acordo com quanto se pretende vender (de acordo com a unidade de cada recurso). Tipo = ferro | aco | carvao | mad | viga | eletr (abreviaturas baseadas nos nomes dos recursos em minúsculas e sem letras acentuadas)."},
									{"cont", {"<tipo>"}, "Contrata um trabalhador de um dado tipo e este, tal como dito anteriormente, vai para a zona de pasto à espera de ordens do jogador. Tipo = oper | len | miner (abreviaturas baseadas nos nomes dos recursos em minúsculas e sem letras acentuadas)."},
									{"list", {"<linha>", "<coluna>"}, "Obtém a informação do jogo, globalmente se não for indicada nenhuma linha.coluna, ou detalhada acerca de uma zona caso a sua posição linha coluna seja indicada."},
									{"vende", {"<linha>", "<coluna>"}, "Vende o edifício existente na zona indicada na linha e coluna especificadas. Recupera os € gastos na sua construção mas não os recursos adicionalmente usados (exemplo, as vigas na mina). Os recursos armazenados no edifício em questão são automaticamente vendidos e os € resultantes passam para o jogador."},
									{"next", {""}, "Termina a fase de recolha de comandos e desencadeia as ações necessárias ao seu processamento."},
									{"save", {"<nome>"}, "Grava o estado do jogo em memória, associando-lhe um nome. Esta ação consiste em fazer uma espécie de savegame para memória, possibilitando ao jogador manter em memória diversos snapshots do jogo, correspondentes a diversos momentos, permitindo-lhe a qualquer momento recuperar um desses momentos. O jogo continua ativo, mas a cópia feita para memória já não será afetada pelos comandos entretanto escritos a partir deste momento."},
									{"load", {"<nome>"}, "Recupera um dado estado do jogo em memória, identificado ao nome indicado, e carrega-o. O jogo recuperado passa a ser o que está em efeito: os comandos passam a agir sobre este."},
									{"apaga", {"<nome>"}, "Apaga um determinado savegame de memória."},
									{"config", {"<ficheiro>"}, "Lê o ficheiro de texto e extrai dele os preços de contratação dos trabalhadores e de compra dos edifícios. São configurados apenas os valores base de € e não os números de recursos adicionais (ex.: número de vigas para a mina). Os valores lidos sobrepõe-se aos indicados no enunciado, que apenas são considerados enquanto não for lido um ficheiro de configuração. O ficheiro tem o conteúdo em que cada linha tem duas palavras separadas por um espaço: nome da coisa (edifício ou trabalhador) e preço (apenas aparte dos €). Os nomes são os mesmos usados nos comandos de contratação e de construção."},
									{"debcash", {"<valor>"}, "Adicina a quantidade de € especificada em valor. A quantidade pode ser positiva (adicionar) ou negativa (remove. Serve para debug e teste."},
									{"debed", {"<tipo>", "<linha>", "<coluna>"}, "Adiciona um edifício a custo zero na zona linha, coluna, respeitando as restrições de não poder haver mais do que um edifício na zona. Serve para debug e teste."},
									{"debkill", {"<id>"}, "Remove o trabalhador com a identificação id. Serve para debug e teste."}};
	public:
		void	startSimulation(void);
		int		getNumber(void);
		void	tryExecuteCommand(void);
		bool	validateArguments(Command &c, vector<string> arguments);
		int		getCommandIndex(string command);
		vector<string> split(const string &s);
};

#endif // INTERFACE_
