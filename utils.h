#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

void	displayFile(std::string filename);
std::string	getCommand(std::vector<std::string> options, std::string question);
int		getNumberBetween(int a, int b, std::string question);

#endif
