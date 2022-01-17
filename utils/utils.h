#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

void	displayFile(const std::string& filename);
std::vector<std::string> readFile(const std::string& filepath);
std::string	getOption(std::vector<std::string> options, const std::string& question);
int		getNumberBetween(int a, int b, const std::string& question);
std::vector<std::string>	split(const std::string &s);
bool	contains(std::vector<std::string>, const std::string &str);
int		toInt(const std::string &str);
float	toFloat(const std::string &str);



#endif
