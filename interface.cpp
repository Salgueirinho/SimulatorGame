#include <iostream>
#include <sstream>
#include "interface.h"
#include "comando.h"
#include "ilha.h"

using namespace std;

void	Interface::startSimulation(void)
{
	Interface interface;
	int	lines;
	int	columns;

	srand((unsigned) time(0));

	while (lines < 3 || 8 < lines)
	{
		cout << "Please insert the number of lines for the island grid: ";	
		lines = interface.getNumber();
		if (lines < 3 || 8 < lines)
			cout << "Please insert a value between 3 and 8." << endl;
	}
	while (columns < 3 || 16 < columns)
	{
		cout << "Please insert the number of columns for the island grid: ";	
		columns = interface.getNumber();
		if (columns < 3 || 16 < columns)
			cout << "Please insert a value between 3 and 16." << endl;
	}
	Ilha ilha(lines, columns);
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
	return true;
}

void	Interface::tryExecuteCommand(Ilha& ilha)
{
	string					command_args;
	int							index = -1;

	while (1)
	{
		cout << "Command: ";
		
		getline(cin >> ws, command_args);
		vector<string> command_args_ = split(command_args);
		index = getCommandIndex(command_args_[0]);
		if (index >= 0)
		{
			cout << "This command is valid. Congrats!" << endl;
			Command &command = commands[index];
			command_args_.erase(command_args_.begin());
			if (validateArguments(command, command_args_))
			{
				cout << "The number of arguments provided is correct. Congrats!" << endl;
				if (executeCommand(command.getName(), command_args_, ilha))
				{
					cout << "The command was succesfully executed." << endl;
					break;
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
	else
		return (false);
}
