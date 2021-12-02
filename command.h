#ifndef COMMAND_H
#define COMMAND_H

std::vector<std::string>	split(const std::string &s);
bool	checkCommand(const std::vector<std::string> &command);
bool	checkArguments(const std::vector<std::string> &command, std::pair<std::string, std::vector<std::string>> command_pair);
std::string	getCommand();

#endif
