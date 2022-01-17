#include "Game.h"
#include "../errors/errors.h"

void Game::list()
{
    this->command_output = island->getAllInfoAsString() ;
}
int    Game::list(int x, int y)
{
    if (x >= 0 && x <= island->getRows()  -1 && y >= 0 && y <= island->getColumns()-1)
    {
        this->command_output =  island->getZoneInfoAsString(x, y) ;
        return 1;
    }else
        return COORDINATE_ERROR;
}
void Game::nextTimeOfDay()
{
  if (this->time_of_day == "Morning")
    this->time_of_day = "Noon";
  else if (this->time_of_day == "Noon")
    this->time_of_day = "Dusk";
  else if (this->time_of_day == "Dusk")
  {
    this->time_of_day = "Morning";
    this->day++;
  }
}
void Game::turnOnOffBuilding(const std::vector<std::string> &command)
{
  if(island->zones[toInt(command[1])][toInt(command[2])]->getBuilding() == nullptr)
  {
    this->command_output =  "This zone has no building";
  }
  else if(island->zones[toInt(command[1])][toInt(command[2])]->getBuilding()->active)
  {
    island->zones[toInt(command[1])][toInt(command[2])]->getBuilding()->deactivate();
  }
  else
  {
    island->zones[toInt(command[1])][toInt(command[2])]->getBuilding()->activate();
  }
}
void Game::build(const std::vector<std::string> &command, int day)
{
  if (this->island->zones[toInt(command[2])][toInt(command[3])]->getBuilding() == nullptr )
  {
    if (doBuildingPayment(command))
    {
      command_output = "New Building";
      island->zones[toInt(command[2])][toInt(command[3])]->setBuilding(command[1], day);
    }
    else
      command_output = "Not enough resources";
  }
  else
    command_output = "That zone has already a building";
}
void Game::levelUpBuilding(const std::vector <std::string> &command)
{
  Building *building = island->zones[toInt(command[1])][toInt(command[2])]->getBuilding();

  if (building!= nullptr && building->getLevel() >=1 && building->getLevel() <5)
  {
    if (doLevelUpPayment(building->getType()))
    {
      building->levelUp();
      command_output = "Level up successful";
    }
    else
    {
      command_output = "Level up failed";
    }
  }
  else
  {
    command_output = "Level up failed";
  }
}
void Game::sell(const std::vector <std::string> &command)
{
  if(contains({"ferro","aco","carvao","mad","viga","eletr"}, command[1]))
  {
    sellResources(command);
  }
  else
  {
    resources.cash += island->zones[toInt(command[1])][toInt(command[2])]->sellBuilding(Game::prices);
  }
}
void Game::hireWorker(const std::vector <std::string> &command, int d)
{
  if (doHiringPayment(command))
  {
    command_output = "New Worker";
    this->island->hire(command[1], d);
  }
  else
    command_output = "Not enough resources";
}

void Game::move(const std::vector<std::string> &command)
{
  float id = toFloat( command[1]);
  int row = toInt(command[2]);
  int column = toInt(command[3]);

  if(this->island->move(id, row, column))
  {
    command_output = "Worker Moved with success!";
  } else
  {
    command_output = "Something went wrong";
  }
}
void Game::applyConfig(const std::vector<std::string> &command)
{
  std::cout << "Config command" << std::endl;
  setConfig(command[1]);
}
void Game::execFile(const std::string &filepath )
{
  exec(filepath);
}

void Game::addDebCash(int cash)
{
  this->resources.cash += cash;
}
void Game::addDebBuilding(const std::vector<std::string> &command, int day)
{
  island->zones[toInt(command[2])] [toInt(command[3])]->setBuilding(command[1], day);
}
void Game::debkill(const float id)
{
  island->killWorkerID(id);
}