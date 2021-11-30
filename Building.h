#ifndef BUILDING_H
#define BUILDING_H

class Building {
	public:
		virtual std::string getType() const = 0;
};

class IronMine : public Building {
	public:
		std::string getType() const override {return "mnF";};
};

class CoalMine : public Building {
	public:
		std::string getType() const override {return "mnC";};
};

class PowerPlant : public Building {
	public:
		std::string getType() const override {return "cen";};
};

class Battery : public Building {
	public:
		std::string getType() const override {return "bat";};
};

class Foundry : public Building {
	public:
		std::string getType() const override {return "fun";};
};

class BuildingX : public Building {
	public:
		std::string getType() const override {return "edX";};
};

#endif
