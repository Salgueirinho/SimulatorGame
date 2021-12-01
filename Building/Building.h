#ifndef BUILDING_H
#define BUILDING_H

#include <string>

class Building {
	public:
		virtual std::string getType() const = 0;
		virtual void	work() const = 0;
		virtual	~Building() = default;
		void	activate();
		void	deactivate();
	private:
		bool	active = false;
};

#endif
