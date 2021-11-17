#include <iostream>
#include <vector>
#include <algorithm>
#include "comando.h"

using namespace std;

void	Comando::command(void)
{
	string	command;
	vector<string> commands {"exec", "cons", "ligia", "des", "move", "vende", "cont", "list", "next", "save", "load", "apaga", "config", "debcash", "debed", "debkill"};
	while (!count(commands.begin(), commands.end(), command))
	{
		cout << "command: ";
		cin >> command;
		if (!count(commands.begin(), commands.end(), command))
			cout << "Please insert a valid command" << endl;
	}
}
