#ifndef FILES_H
#define FILES_H

#include <string>

using namespace std;

class File {
	private:
	public:
		int	display(string filepath);
    int loadConfig(string filepath);
    //vector<string> File::splitStringInt(const string &s);
};

#endif // FILES_H
