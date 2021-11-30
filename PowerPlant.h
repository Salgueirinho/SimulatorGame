#ifndef POWERPLANT_H
#define POWERPLANT_H

class PowerPlant : public Building {
	public:
		std::string getType() const override {return "cen";};
};

#endif
