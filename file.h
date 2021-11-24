#ifndef FILES_H
#define FILES_H

#include <string>
#include <vector>

using namespace std;

class File {
	private:
	public:
		int	display(string filepath);
		vector<string> readFile(string filepath); // lê para memoria linha a linha de um ficheiro
		//vector<string> File::splitStringInt(const string &s);
};

#endif // FILES_H
