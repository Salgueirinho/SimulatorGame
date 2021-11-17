#include <iostream>
#include "interface.h"
#include "ilha.h"
#include "menu.h"

using namespace std;

int	main(void)
{
	Menu	menu;
	Interface	interface;

	menu.show();
	switch(menu.askOption())
	{
		case 1:
			interface.startSimulation();
			break;
		case 2:
			menu.showInstructions();
			break;
	}
	return 0;
}
