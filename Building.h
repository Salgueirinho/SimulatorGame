#ifndef BUILDING_H
#define BUILDING_H

class Building {
	public:
		virtual std::string getType() const = 0;
	private:
};

class IronMine : public Building {
	public:
		std::string getType() const override {return "IronMine";};
	private:
};

class CoalMine : public Building {
	public:
		std::string getType() const override {return "CoalMine";};
	private:
};

class PowerPlant : public Building {
	public:
		std::string getType() const override {return "PowerPlant";};
	private:
};

class Battery : public Building {
	public:
		std::string getType() const override {return "Battery";};
	private:
};

class Foundry : public Building {
	public:
		std::string getType() const override {return "Foundry";};
	private:
};

class BuildingX : public Building {
	public:
		std::string getType() const override {return "BuildingX";};
	private:
};

#endif
