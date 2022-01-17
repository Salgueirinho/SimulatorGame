#ifndef DESERT_H
#define DESERT_H

#include "Zone.h"

class Desert : public Zone {
	public:
    std::string getType() const override {return "dsr";};
		~Desert() override = default;
    void work(Resources& resources, int day) override;

  private:

};

#endif
