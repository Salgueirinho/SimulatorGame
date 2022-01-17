//#include <sstream>
#include <vector>
#include <iostream>
#include "Game.h"
#include "../errors/errors.h"
//#include "../Interface/Interface.h"
//#include "../utils/utils.h"

std::map<std::string, int> Game::prices = {
  //Buildings
  {"mnF",	100},
  {"mnC",  100},
  {"bat",	    10},
  {"cen",	    15},
  {"fun",	  	10},
  {"ser",	  	10},
  {"edX",		100},
  // Workers
  {"min",		10},
  {"len",		  20},
  {"ope",		15}};
std::map<std::string, std::vector<std::string>> Game::commands = {
	{"exec",		{"nomeFicheiro"}},
	{"cons",		{"tipo", "linha", "coluna"}},
	{"liga",		{"linha", "coluna"}},
  {"levelup",			{"linha", "coluna"}},
  {"des",			{"linha", "coluna"}},
	{"move",		{"id", "linha", "coluna"}},
	{"vende",		{"tipo", "quanto"}},
	{"cont",		{"tipo"}},
	{"list",		{"linha", "coluna"}},
	{"vende",		{"linha", "coluna"}},
	{"next",		{}},
	{"save",		{"nome"}},
	{"load",		{"nome"}},
	{"apaga",		{"ficheiro"}},
	{"config",	{"valor"}},
	{"debcash",	{"valor"}},
	{"debed",		{"tipo", "linha", "coluna"}},
	{"debkill",	{"id"}},
	{"exit",		{}}};

int Game::executeCommand(const std::vector<std::string> &command)
{
if (command[0] == "exit")
{
exit = true;
}
else if (command[0] == "list" && command.size() == 1)
{
list();
}
else if (command[0] == "list" && command.size() == 3)
{
list(toInt(command[1]), toInt(command[2]));
}
else if (command[0] == "next")
{
this->nextTimeOfDay();
}
else if (command[0] == "exec")
{
execFile(command[1]);
}
else if (command[0] == "cons")
{
build(command, day);
}
else if (command[0] == "levelup")
{
  levelUpBuilding(command);
}
else if (command[0] == "liga")
{
turnOnOffBuilding(command);
}
else if (command[0] == "des")
{
  turnOnOffBuilding(command);
}
else if (command[0] == "move")
{
move(command);
}
else if (command[0] == "vende")
{
sell(command);
}
else if (command[0] == "cont")
{
  hireWorker(command, this->day);
}
else if (command[0] == "save")
{
  command_output = "Not working right now!";
}
else if (command[0] == "load")
{
  command_output = "Not working right now!";
}
else if (command[0] == "apaga")
{
  command_output = "Not working right now!";
}
else if (command[0] == "config")
{
  applyConfig(command);
}
else if (command[0] == "debcash")
{
addDebCash(toInt(command[1]));
}
else if (command[0] == "debed")
{
addDebBuilding(command, day);
}
else if (command[0] == "debkill")
{
  debkill(toFloat(command[1]));
}
return 0;
}
bool	Game::validateArgsFormat(const std::vector<std::string> &command)
{
if (contains({"exec", "next", "save", "load", "apaga", "config", "exit"}, command[0])
|| (command[0] == "list" && command.size() == 1))
return true;
else if (contains({"liga", "des", "list","levelup"}, command[0]))
  return toInt(command[1]) != -1 && toInt(command[2]) != -1;
else if (contains({"cons", "debed"}, command[0]))
return (contains({"mnF","mnC","bat","cen","fun", "ser","edX"}, command[1])
&& toInt(command[2]) != -1 && toInt(command[3]) != -1);
else if (contains({"vende"}, command[0]))
    return (contains({"ferro","aco","carvao","mad","viga","eletr"}, command[1])
            || (toInt(command[1]) != -1 && toInt(command[2]) != -1));
else if (command[0] == "move")
return toFloat(command[1]) != -1 && toInt(command[2]) != -1
&& toInt(command[3]) != -1;
else if (command[0] == "cont")
return contains({"len", "min", "ope"}, command[1]);
else if (command[0] == "debcash")
return toInt(command[1]) != -1;
else if (command[0] == "debkill")
return (toFloat(command[1]) != -1);
return false;
}
bool	Game::validateArgsNumber(const std::vector<std::string> &command, const std::pair<std::string, std::vector<std::string>> &command_pair)
{
if (command_pair.second.size() == command.size() - 1
  || (command_pair.first == "list" && command.size() == 1)
  || (command_pair.first == "vende" && command.size() == 3))
return true;
return false;
}
int	Game::checkCommand(const std::vector<std::string> &command)
{
for (auto const& elem : Game::commands)
{
if (elem.first == command[0])
{
  if (validateArgsNumber(command, elem))
  {
    if (validateArgsFormat(command))
      return 0;
    else
      return FORMAT_ARGS_ERROR;
  }
  else
    return NUMBER_ARGS_ERROR;
}
}
return COMMAND_ERROR;
}

std::string Game::getEssentialInfo() const
{
std::ostringstream oss;
oss << "Day: " << this->day << std::endl;
oss << "Time of the day: " << this->time_of_day << std::endl;
oss << "Cash: " << this->resources.cash << std::endl;
oss << "Iron: " << this->resources.iron << std::endl;
oss << "Steel: " << this->resources.steel << std::endl;
oss << "Coal: " << this->resources.coal << std::endl;
oss << "Wood: " << this->resources.wood << std::endl;
oss << "Wood Planks: " << this->resources.wood_planks << std::endl;
oss << "Electricity: " << this->resources.electricity << std::endl;
return oss.str();
}

bool	Game::checkConf(std::string conf)
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
void	Game::setConf(std::string conf, int val_, int classPlaceMarker)
{
  (void) classPlaceMarker;
  if (!conf.compare("min"))
  {
    std::cout << "a configurar o preço dos mineiros para " << val_ << std::endl;
    Game::prices["min"] = val_;
  }
  else if (!conf.compare("len"))
  {
    std::cout << "a configurar o preço dos lenhadores para " << val_ << std::endl;
    Game::prices["len"] = val_;
  }
  else if (!conf.compare("ope"))
  {
    std::cout << "a configurar o preço dos operadores para " << val_ << std::endl;
    Game::prices["ope"] = val_;
  }
  else if (!conf.compare("mnC"))
  {
    std::cout << "a configurar o preço das minas de carvão para " << val_ << std::endl;
    Game::prices["mnC"] = val_;
  }
  else if (!conf.compare("mnF"))
  {
    std::cout << "a configurar o preço das minas de ferro para " << val_ << std::endl;
    Game::prices["mnF"] = val_;
  }
  else if (!conf.compare("elec"))
  {
    std::cout << "a configurar o preço das centrais elétricas para " << val_ << std::endl;
    Game::prices["cen"] = val_;
  }
  else if (!conf.compare("bat"))
  {
    std::cout << "a configurar o preço das baterias para " << val_ << std::endl;
    Game::prices["bat"] = val_;
  }
  else if (!conf.compare("fun"))
  {
    std::cout << "a configurar o preço das fundições para " << val_ << std::endl;
    Game::prices["fun"] = val_;
  }
}
void Game::setConfig(const std::string& filepath)
{
  std::fstream file;

  file.open(filepath, std::fstream::in);
  if (!file)
  {
    std::cout << filepath << " falhou ao abrir!" << std::endl;
  }
  else
  {
    std::string conf;
    std::string val;
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
            std::stringstream ss(val);
            ss >> val_;
            val.clear();
            if (val_ <= 0)
              std::cout << "valor \"" << val <<
                   "\" não reconhecido como valor positivo para "
                   << conf << std::endl;
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

void Game::exec(const std::string &fileptah)
{
  int error_code;
  std::vector<std::string> instructions = readFile(fileptah);
  std::vector<std::string> command;
  for(auto line: instructions)
  {
    command = split(line);
    error_code = Game::checkCommand(command);
    std::cout << parseErrorCode(error_code);
    if (command[1] != fileptah)
      this->executeCommand(command);
  }
}

void Game::checkEndOfGame()
{
  if (resources.cash == 0 && island->getNumberOfWorkers() <= 0)
  {
    this->exit = true;
    command_output = "Game Over";
  }
}
void Game::simulateMorning(int day)
{
  //Reset Workers moves
  for (int i=0 ; i< island->getRows(); i++)
  {
    for (int j=0 ; j< island->getColumns(); j++)
    {
      island->zones[i][j]->resetWorkersMovesLeft();
    }
  }

  // Swamp 10 day effect to buildings and workers
  Building * building;
  std::vector<std::vector<int>> swamps = island->getSpecificZone("pnt");
  for (auto & swamp : swamps)
  {
    building = island->zones[swamp[0]][swamp[1]]->getBuilding();
    if(building != nullptr && day - building->built_day  >= 10){
      command_output = "RIP Building and workers";
      island->zones[swamp[0]][swamp[1]]->removeBuilding();
      island->zones[swamp[0]][swamp[1]]->removeAllWorkers();
      }
    }

  // Probability of workers quiting
  for (int i=0 ; i< island->getRows(); i++)
  {
    for (int j=0 ; j< island->getColumns(); j++)
    {
      if (island->zones[i][j]->getType() != "pas")
      {
        island->zones[i][j]->handleQuitingWorkers(day);
      }
    }
  }
}
void Game::simulateDusk(int day)
{
  island->simulateDusk(resources, day);
}

int Game::doHiringPayment(const std::vector<std::string> &command)
{
  int valid_payment = 0;
  int payment_price = Game::prices[command[1]];

  if (command[1] == "min")
  {
    if (resources.cash >= payment_price)
    {
      resources.cash -= payment_price;
      valid_payment = 1;
    }
  }
  else if (command[1] == "ope")
  {
    if (resources.cash >= payment_price) {
      resources.cash -= payment_price;
      valid_payment = 1;
    }
  }
  else if (command[1] == "len") {
    if (resources.cash >= payment_price) {
      resources.cash -= payment_price;
      valid_payment = 1;
    }
  }
  return valid_payment;
}
int Game::doBuildingPayment(const std::vector<std::string> &command)
{
  int valid_payment = 0;
  std::string zone_type = this->island->zones[toInt(command[2])][toInt(command[3])]->getType();
  int payment_price = Game::prices[command[1]];

  if (zone_type == "mnt")
  {
    payment_price = payment_price * 2;
  }

  if (command[1] == "mnF") {
    if (resources.wood_planks >= 10 || resources.cash >= payment_price) {
      if (resources.wood_planks - 10 >= 0) {
        resources.wood_planks -= 10;
        valid_payment = 1;
      } else if (resources.wood_planks - 10 < 0) {
        resources.cash -= ((payment_price/ 10 ) * -1 * (resources.wood_planks - 10));
        resources.wood_planks = 0;
        valid_payment = 1;
      }
    }
  }
  else if (command[1] == "mnC")
  {
    if (resources.wood_planks >= 10 || resources.cash >=  payment_price) {
      if (resources.wood_planks - 10 >= 0) {
        resources.wood_planks -= 10;
        valid_payment = 1;
      } else if (resources.wood_planks - 10 < 0) {
        resources.cash -= ((payment_price/ 10 )  * -1 * (resources.wood_planks - 10));
        resources.wood_planks = 0;
        valid_payment = 1;
      }
    }
  }
  else if (command[1] == "cen") {
    if (resources.cash >= payment_price) {
      resources.cash -= payment_price;
      valid_payment = 1;
    }
  }
  else if (command[1] == "bat")
  {
    if (resources.cash >= payment_price && resources.wood_planks >= 10)
    {
      resources.cash -= payment_price;
      resources.wood_planks -= 10;
      valid_payment = 1;
    }
  }
  else if (command[1] == "fun")
  {
    if (resources.cash >= payment_price) {
      resources.cash -= payment_price;
      valid_payment = 1;
    }
  }
  else if (command[1] == "ser")
  {
    if (resources.cash >= payment_price) {
      resources.cash -= payment_price;
      valid_payment = 1;
    }
  }
  else if (command[1] == "edX")
  {
    if ( resources.cash >= payment_price)
    {
      resources.cash -= payment_price;
      valid_payment = 1;
    }
  }
  return valid_payment;
}
int Game::doLevelUpPayment(const std::string &building_type)
{
  int valid_payment = 0;
  if(building_type == "mnF")
  {
    if(resources.cash >= 15 && resources.wood_planks >=1)
    {
      resources.cash -= 15;
      resources.wood_planks--;
      valid_payment = 1;
    }
  }
  else if (building_type == "mnC")
  {
    if(resources.cash >= 10 && resources.wood_planks >=1)
    {
      resources.cash -= 10;
      resources.wood_planks--;
      valid_payment = 1;
    }
  }
  else if (building_type == " bat")
  {
    if (resources.cash >= 5)
    {
      resources.cash -= 5;
      valid_payment = 1;
    }
  }
  return valid_payment;
}
void Game::sellResources(const std::vector<std::string> &command)
{
  int amount = toInt(command[2]);
  if(amount > 0)
  {
    if (command[1] == "ferro")
    {
      if (resources.iron >=amount)
      {
        resources.iron -= amount;
        resources.cash += amount;
      }
    } else if (command[1] == "aco")
    {
      if (resources.steel >= amount)
      {
        resources.steel -= amount;
        resources.cash += amount * 2;
      }
    } else if (command[1] == "carvao")
    {
      if (resources.coal >= amount)
      {
        resources.coal -= amount;
        resources.cash += amount;
      }
    } else if (command[1] == "viga")
    {
      if (resources.wood_planks >= amount)
      {
        resources.wood_planks -= amount;
        resources.cash += amount * 2;
      }
    } else if (command[1] == "eletr")
    {
      if (resources.electricity >= amount)
      {
        resources.electricity -= amount;
        resources.cash += amount * 2;
      }
    } else if (command[1] == "mad")
    {
      if (resources.wood >= amount)
      {
        resources.wood -= amount;
        resources.cash += amount;
      }
    }
  }
}
