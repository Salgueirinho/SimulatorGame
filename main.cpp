#include <iostream>
#include "menu.h"
#include "ilha.h"
#include <ctime>

using namespace std;

int	main(void)
{
	Menu menu;

	menu.show();
	switch(menu.askOption())
	{
		case 1:
			break;
		case 2:
			menu.showInstructions();
			break;
	}
	srand((unsigned) time(0));
	Ilha ilha(4, 4);
	ilha.setZoneTypes();
	ilha.displayZones();
	return 0;
}
