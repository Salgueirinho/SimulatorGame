#include <iostream>
#include <sstream>
#include <ctime>
#include "interface.h"
#include "comando.h"
#include "ilha.h"
#include "file.h"
#include "tempo.h"

using namespace std;

vector<vector<int>>	getPasto(Ilha ilha)
{
	vector<vector<int>> pastagens;
	vector<int> coords;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (ilha.zonas[i][j].getZone() == "pas")
			{
				coords.push_back(i);
				coords.push_back(j);
				pastagens.push_back(coords);
				coords.clear();
			}
		}
	}
	return (pastagens);
}

void	Interface::startSimulation(void)
{
	Interface interface;
	int	lines;
	int	columns;

	srand((unsigned) time(0));

	Ilha ilha;
	ilha.setZoneTypes();
	while (1)
	{
		ilha.display();
		interface.tryExecuteCommand(ilha);
	}
}

int		Interface::getNumber(void)
{
	string	number_string;
	int			n = 0;
	while (n <= 0)
	{
		cin >> number_string;
		stringstream	n_stream(number_string);
		n_stream >> n;
		if (n_stream.fail())
			cout << "Please write a numeric value!" << endl;
		else
		{
			if (n <= 0)
				cout << "Please insert a positive number" << endl;
		}
	}
	return (n);
}

bool	Interface::executeCommand(string command, vector<string> args, Ilha& ilha)
{
	vector<int>	int_args;
	int			buffer;
	if (command.compare("cons") == 0)
	{
		if (args[0].compare("minaferro"))
		{
			cout << "First argument (type of building) provided in the wrong format." << endl;
			return false;
		}
		stringstream ss(args[1]);
		ss >> buffer;
		int_args.push_back(buffer);
		if (ss.fail())
		{
			cout << "Second argument (X coordinate) provided in the wrong format." << endl;
			return false;
		}
		stringstream ss2(args[2]);
		ss2 >> buffer;
		int_args.push_back(buffer);
		if (ss.fail())
		{
			cout << "Third argument (Y coordinate) provided in the wrong format." << endl;
			return false;
		}
		ilha.zonas[int_args[0] - 1][int_args[1] - 1].setEdificio("mnF");
	}
	// contratar mineiros
	if (command.compare("cont") == 0)
	{
		if (args[0].compare("miner"))
		{
			cout << "First argument (type of worker) provided in the wrong format." << endl;
			return false;
		}

		Trabalhador worker(args[0]);
		vector<vector<int>> pastagens = getPasto(ilha);
		int r = rand() % pastagens.size();
		ilha.zonas[pastagens[r][0]][pastagens[r][1]].setTrabalhador(worker);
	}
	//exec command
	if (command.compare("exec") == 0)
	{
		File instructions_file;
		vector<string> instructions = instructions_file.readFile(args[0]);
		cout << args[0] << endl;
		for (int i = 0; i < instructions.size(); i++)
		{
			validateCommand(ilha, instructions[i]);
		}

	} 

	if (command.compare("config") == 0)
	{

		vector<string> confs;
		File config_file;
		//returns line by line of a file
		confs = config_file.readFile(args[0]);
	}
    if (command.compare("list") == 0)
    {
        if (!args.empty())
        {
            stringstream ss(args[0]);
            ss >> buffer;
            int_args.push_back(buffer);
            if (ss.fail()) {
                cout << "Second argument (X coordinate) provided in the wrong format." << endl;
                return false;
            }
            stringstream ss2(args[1]);
            ss2 >> buffer;
            int_args.push_back(buffer);
            if (ss.fail()) {
                cout << "Third argument (Y coordinate) provided in the wrong format." << endl;
                return false;
            }
            cout << ilha.getInfoAsString(int_args[0] - 1, int_args[1] - 1) << endl;
        }
    }

	return true;
}

bool	Interface::executeList(Ilha& ilha)
{
    cout << ilha.getAllInfoAsString() << endl;
}

bool	Interface::validateCommand(Ilha& ilha, string command_args)
{
	vector<string> command_args_ = split(command_args);
	int index = getCommandIndex(command_args_[0]);
	if (index >= 0)
	{
		cout << "This command is valid. Congrats!" << endl;
		Command &command = commands[index];
		command_args_.erase(command_args_.begin());
		if (validateArguments(command, command_args_))
		{
			cout << "The number of arguments provided is correct. Congrats!" << endl;
            if (!command_args.compare("list"))
            {
                executeList(ilha);
                return (true);
            }
			else if (executeCommand(command.getName(), command_args_, ilha))
			{
				cout << "The command was succesfully executed." << endl;
				return (true);
			}
			else
			{
				cout << "The command couldn't be executed." << endl;
			}
		}
		else
		{
			cout << "The number of arguments provided is incorrect. Try again!" << endl;
		}
	}
	else
	{
		cout << "This command is invalid. Try again!" << endl;
	}
	return (false);
}

void	Interface::tryExecuteCommand(Ilha& ilha)
{
	string					command_args;
	bool						validity = false;
	int							index = -1;

	while (validity == false)
	{
		cout << "Command: ";
		getline(cin >> ws, command_args);
		validity = validateCommand(ilha, command_args);
	}
}

vector<string> Interface::split(const string &s)
{
	vector<string> result;
	stringstream ss (s);
	string item;

	while (getline (ss, item, ' ')) {
		result.push_back (item);
	}
	return (result);
}

int		Interface::getCommandIndex(string command)
{
	for (int i = 0; i < commands.size(); i++) {
		if (commands[i].getName().compare(command) == 0)
			return (i);
	}
	return (-1);
}

bool	Interface::validateArguments(Command &command, vector<string> arguments)
{
	if (command.getArgs().size() == arguments.size())
		return (true);
    else if (!command.getName().compare("list") && arguments.size() == 0)
        return (true);
    else
    {
        return (false);
    }
}
