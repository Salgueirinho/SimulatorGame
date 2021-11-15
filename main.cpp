#include <iostream>
#include "menu.h"
#include "ilha.h"

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
	return 0;
}
