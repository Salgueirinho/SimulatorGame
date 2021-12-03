#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>

std::vector<std::string>	getCommand();
void	executeCommand(const std::vector<std::string> &command);

#endif
