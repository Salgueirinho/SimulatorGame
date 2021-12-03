#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>

bool	checkCommand(const std::vector<std::string> &command);
bool	checkArguments(const std::vector<std::string> &command, std::pair<std::string, std::vector<std::string>> command_pair);
void	executeCommand(const std::vector<std::string> &command);
std::vector<std::string>	getCommand();

#endif
