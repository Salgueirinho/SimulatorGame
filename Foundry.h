#ifndef FOUNDRY_H
#define FOUNDRY_H

class Foundry : public Building {
	public:
		std::string getType() const override {return "fun";};
};

#endif
