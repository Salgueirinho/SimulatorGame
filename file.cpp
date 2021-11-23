#include <fstream>
#include <iostream>
#include <string>
#include "file.h"
#include <vector>

using namespace std;

int	File::display(string filepath)
{
	char			ch;
	ifstream		fs;

	fs.open(filepath);
	// protecting fstream::open() for failsafes
	if (!fs)
	{
		cout << "Unable to open file" << endl;
		return (0);
	}
	// shows file character by character
	while (!fs.eof())
	{
		fs.get(ch);
		cout << ch;
	}
	fs.close();
	return (1);
}

vector<string> File::readFile(string filepath){
  string line;
  ifstream fs;
  vector<string>string_vector;
  fs.open(filepath);
  if(!fs){
    cout << "Ficheiro não existe / Erro a abrir ficheiro" << endl;
    return {};
  }
  while (getline(fs,line)){
    string_vector.push_back(line);
  }
  fs.close();
  return string_vector; 
}


/*
vector<string> File::splitStringInt(const string &s)
{
	stringstream ss (s);
	string item;
  vector<string> s_separada;

	while (getline (ss, item, ' ')) {
    s_separada.push_back(item);
	}

	return (0);
}
*/
