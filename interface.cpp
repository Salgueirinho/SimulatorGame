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
		ilha.displayZones();
		interface.tryExecuteCommand();
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

void	Interface::tryExecuteCommand(void)
{
	string					command_args;
	int							success = 0;
	int							index = -1;

	while (success == 0)
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
			success = validateArguments(command, command_args_);
			if (success)
			{
				cout << "The number of arguments provided is correct. Congrats!" << endl;
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
