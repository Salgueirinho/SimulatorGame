#ifndef COALMINE_H
#define COALMINE_H

class CoalMine : public Building {
	public:
		std::string getType() const override {return "mnC";};
};

#endif
