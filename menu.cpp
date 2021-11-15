#include <iostream>
#include <sstream>
#include "menu.h"

using namespace std;

void	Menu::show(void)
{
	cout << endl;
	cout << "### # ### # # #   #  ##   #  ## " << endl;
	cout << "#   # # # # # #  # # # # # # # #" << endl;
	cout << "### # # # # # #  ### # # # # ## " << endl;
	cout << "  # # # # # # #  # # # # # # # #" << endl;
	cout << "### # # #  #  ## # # ##   #  # #" << endl;
	cout << endl;
	cout << "Choose one of the following options:" << endl;
	cout << "(1) -> Play game" << endl;
	cout << "(2) -> Show instructions" << endl;
	cout << "(3) -> ..." << endl;
}

int	Menu::askOption(void)
{
	string	option_string;
	int	option = 0;
	int	validity = 0;

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
