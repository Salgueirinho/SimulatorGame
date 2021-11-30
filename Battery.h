#ifndef BATTERY_H
#define BATTERY_H

class Battery : public Building {
	public:
		std::string getType() const override {return "bat";};
};

#endif
