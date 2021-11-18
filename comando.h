#ifndef COMANDO_H
#define COMANDO_H

#include <vector>
#include <string>

using namespace std;

class Command {
	private:
		string					name;
		vector<string>	args;
		string					desc;
	public:
		Command(string name, vector<string> args, string desc);
		string	getName(void);
		vector<string>	getArgs(void);
		string	getDesc(void);
};

#endif // COMANDO_H
