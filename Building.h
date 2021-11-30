#ifndef BUILDING_H
#define BUILDING_H

class Building {
	public:
		virtual std::string getType() const = 0;
	private:
};

class IronMine : public Building {
	public:
		std::string getType() const override {return "mnF";};
	private:
};

class CoalMine : public Building {
	public:
		std::string getType() const override {return "mnC";};
	private:
};

class PowerPlant : public Building {
	public:
		std::string getType() const override {return "elec";};
	private:
};

class Battery : public Building {
	public:
		std::string getType() const override {return "bat";};
	private:
};

class Foundry : public Building {
	public:
		std::string getType() const override {return "fun";};
	private:
};

class BuildingX : public Building {
	public:
		std::string getType() const override {return "edX";};
	private:
};

#endif
