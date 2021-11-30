#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include "utils.h"

void displayFile(const std::string& filepath)
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

std::string	getCommand(std::vector<std::string> options, const std::string& question)
{
	std::string command;

	while (true)
	{
		std::cout << question;
		std::getline(std::cin, command);
		if (std::find(options.begin(), options.end(),  command.substr(0, command.find(' '))) != options.end())
			return command;
		else
			std::cout << "Please insert a valid option/command!" << std::endl;
	}
}

int		getNumberBetween(int a, int b, const std::string& question)
{
	std::string	number_string;
	int	number;

	while (true)
	{
		std::cout << question;
		std::getline(std::cin, number_string);
		std::stringstream ss(number_string);
		ss >> number;
		if (!ss.fail() && (a <= number && number <= b))
			return number;
		else
			std::cout << "Please insert a number between " << a << " and " << b << "!" << std::endl;
	}
}
