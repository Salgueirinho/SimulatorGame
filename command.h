#ifndef COMMAND_H
#define COMMAND_H

bool	checkCommand(const std::vector<std::string> &command);
bool	checkArguments(const std::vector<std::string> &command, std::pair<std::string, std::vector<std::string>> command_pair);
std::string	getCommand();

#endif
