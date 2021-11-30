#ifndef IRONMINE_H
#define IRONMINE_H

class IronMine : public Building {
	public:
		std::string getType() const override {return "mnF";};
};

#endif
