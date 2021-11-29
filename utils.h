#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

void	displayFile(const std::string& filename);
std::string	getCommand(std::vector<std::string> options, const std::string& question);
int		getNumberBetween(int a, int b, const std::string& question);

#endif
