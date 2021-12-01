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

std::string	getOption(std::vector<std::string> options, const std::string& question)
{
	std::string option;

	while (true)
	{
		std::cout << question;
		std::getline(std::cin, option);
		if (std::find(options.begin(), options.end(), option) != options.end())
			return option;
		else
		{
			std::cout << "Please insert a valid option:" << std::endl;
			for (int i = 0; i < (int) options.size(); i++)
				std::cout  << " -" << options[i] << std::endl;
		}
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
