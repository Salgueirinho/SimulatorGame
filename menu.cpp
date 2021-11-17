#include <iostream>
#include <sstream>
#include <string>
#include "file.h"
#include "menu.h"

using namespace std;

void	Menu::show(void)
{
	File file;
	file.display("mainmenu");
}

void	Menu::showInstructions(void)
{
	File file;
	file.display("instructions");
}

int	Menu::askOption(void)
{
	string	option_string;
	int			option = 0;
	bool		validity = false;

	while (validity != 1)
	{
		cout << "Please insert your option: ";
		cin >> option_string;
		stringstream	test_stream(option_string);
		test_stream >> option;
		if (test_stream.fail())
			cout << "Please write a numeric value!\n" << endl;
		else
		{
			validity = validateOption(option);
			if (validity == false)
				cout << "Please choose a valid option" << endl;
		}
	}
	return (option);
}

bool	Menu::validateOption(int option)
{
	switch (option)
	{
		case 1:
			return true;
		case 2:
			return true;
		default:
			return false;
	}
}
