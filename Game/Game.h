#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include "../Island/Island.h"
#include "../utils/utils.h"
#include "../Resources/Resources.h"

class	Game {
  public:
    int day;
    std::string time_of_day;
    Resources resources;
    Island	*island = nullptr;
    bool	exit = false;

    int doHiringPayment(const std::vector<std::string> &command);
    int doBuildingPayment(const std::vector<std::string> &command);
    int doLevelUpPayment(const std::string &building_type);
    void sellResources(const std::vector<std::string> &command);

    //Game simulation
    static std::map<std::string, int> prices;
    std::string getEssentialInfo() const;
    bool checkConf(std::string conf);
    void	setConf(std::string conf, int val_, int classPlaceMarker);
    void setConfig(const std::string& filepath);
    void exec(const std::string& fileptah);

    void checkEndOfGame();
    void simulateMorning(int day);
    void simulateDusk(int day);

    // commands
    std::string command_output;
    static	std::map<std::string, std::vector<std::string>> commands;
    int	executeCommand(const std::vector<std::string> &command);
    static int	checkCommand(const std::vector<std::string> &command);
    void	list();
    int	  list(int x, int y);
    void nextTimeOfDay();
    void turnOnOffBuilding(const std::vector<std::string> &command);
    void build(const std::vector<std::string> &command, int day);
    void levelUpBuilding(const std::vector<std::string> &command);
    void sell(const std::vector<std::string> &command);
    void hireWorker(const std::vector<std::string> &command, int d);
    void move(const std::vector<std::string> &command);
    void applyConfig(const std::vector<std::string> &command);
    void execFile(const std::string &filepath);

    void addDebCash(int cash);
    void addDebBuilding(const std::vector<std::string> &command, int day);
    void debkill(const float id);

  private:
    static bool	validateArgsNumber(const std::vector<std::string> &command, const std::pair<std::string, std::vector<std::string>> &command_pair);
    static bool	validateArgsFormat(const std::vector<std::string> &command);
};

#endif
