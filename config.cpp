#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

bool	checkConf(string conf)
{
	return !(conf.compare("min") && 
			conf.compare("len") &&
			conf.compare("ope") &&
			conf.compare("mnC") &&
			conf.compare("mnF") &&
			conf.compare("elec") &&
			conf.compare("bat") &&
			conf.compare("fun"));
}

void	setConf(string conf, int val_, int classPlaceMarker)
{
	(void) classPlaceMarker;
	if (!conf.compare("min"))
		cout << "a configurar o preço dos mineiros para " << val_ << endl;
	else if (!conf.compare("len"))
		cout << "a configurar o preço dos lenhadores para " << val_ << endl;
	else if (!conf.compare("ope"))
		cout << "a configurar o preço dos operadores para " << val_ << endl;
	else if (!conf.compare("mnC"))
		cout << "a configurar o preço das minas de carvão para " << val_ << endl;
	else if (!conf.compare("mnF"))
		cout << "a configurar o preço das minas de ferro para " << val_ << endl;
	else if (!conf.compare("elec"))
		cout << "a configurar o preço das centrais elétricas para " << val_ << endl;
	else if (!conf.compare("bat"))
		cout << "a configurar o preço das baterias para " << val_ << endl;
	else if (!conf.compare("fun"))
		cout << "a configurar o preço das fundições para " << val_ << endl;
}

void	config(string filename)
{
	fstream file;

	file.open(filename, ios::in);
	if (!file)
	{
		cout << filename << " falhou ao abrir!" << endl;
	}
	else
	{
		string conf;
		string val;
		int val_;
		char ch;

		while (!file.eof())
		{
			ch = file.get();
			if (ch == '\n' && !conf.empty())
				conf.clear();
			else if (ch == ' ' && !conf.empty())
			{
				if (checkConf(conf))
				{
					ch = '#';
					while (ch != ' ' && ch != '\n' && ch != '\0')
					{
						ch = file.get();
						val += ch;
					}
					if (ch != '_')
					{
						stringstream ss(val);
						ss >> val_;
						val.clear();
						if (val_ <= 0)
							cout << "valor \"" << val <<
								"\" não reconhecido como valor positivo para "
								<< conf << endl;
						else
							setConf(conf, val_, 0);
					}
				}
				conf.clear();
			}
			else
				conf += ch;
		}
	}
	file.close();
}
