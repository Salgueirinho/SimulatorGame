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

std::vector<std::string> readFile(const std::string& filepath)
{
  std::string line;
  std::ifstream fs;
  std::vector<std::string> string_vector;
  fs.open(filepath);
  if(!fs)
  {
    std::cout << "Unable to open file \"" << filepath << "\"." << std::endl;
    return {};
  }
  while(std::getline(fs, line))
    string_vector.push_back(line);
  fs.close();
  return string_vector;


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
			for (auto & option_ : options)
				std::cout  << " - " << option_ << std::endl;
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

std::vector<std::string>	split(const std::string &s)
{
	std::vector<std::string>	result;
	std::stringstream	ss(s);
	std::string item;

	while (std::getline(ss, item, ' '))
		result.push_back(item);
	return result;
}

bool	contains(std::vector<std::string> v, const std::string &str)
{
	return (std::find(v.begin(), v.end(), str) != v.end());
}

int		toInt(const std::string &str)
{
	int	num;
	std::stringstream ss(str);
	ss >> num;
	if (ss.fail())
		return -1;
	else
		return num;
}

float	toFloat(const std::string &str)
{
	float	num;
	std::stringstream ss(str);
	ss >> num;
	if (ss.fail())
		return -1;
	else
		return num;
}

