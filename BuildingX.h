#ifndef BUILDINGX_H
#define BUILDINGX_H

class BuildingX : public Building {
	public:
		std::string getType() const override {return "edX";};
};

#endif
