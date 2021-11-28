#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include "utils.h"

void	displayFile(std::string filepath)
{
	std::fstream	fs;
	fs.open(filepath);
	if (!fs)
	{
		std::cout << "Unable to open file \"" << filepath << "\"." << std::endl;
		return ;
	}
	std::cout << fs.rdbuf();
	fs.close();
}

std::string	getOption(std::vector<std::string> options)
{
	std::string option;

	while (1)
	{
		std::getline(std::cin, option);
		if (std::find(options.begin(), options.end(),  option.substr(0, option.find(" "))) != options.end())
			return (option);
		else
			std::cout << "Please insert a valid option/command: ";
	}
}

int		getNumberBetween(int a, int b)
{
	std::string	number_string;
	int	number;

	while (1)
	{
		std::cin >> number_string;
		std::stringstream ss(number_string);
		ss >> number;
		if (!ss.fail() && (a <= number && number <= b))
			return (number);
		else
			std::cout << "Please insert a number between " << a << " and " << b << ": ";
	}
}
