#include "comando.h"

Command::Command(string name, vector<string> args, string desc)
{
	this->name = name;
	this->args = args;
	this->desc = desc;
}

string	Command::getName(void)
{
	return (name);
}

vector<string>	Command::getArgs(void)
{
	return (args);
}

string	Command::getDesc(void)
{
	return (desc);
}
