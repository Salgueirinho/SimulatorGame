#include <fstream>
#include <iostream>
#include <string>
#include "file.h"

using namespace std;

int	File::display(string filepath)
{
	char			ch;
	ifstream		fp;

	fp.open(filepath);
	// protecting fstream::open() for failsafes
	if (!fp)
	{
		cout << "Unable to open file" << endl;
		return (0);
	}
	// shows file character by character
	while (!fp.eof())
	{
		fp.get(ch);
		cout << ch;
	}
	fp.close();
	return (1);
}
