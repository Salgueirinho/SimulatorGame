#include "Interface/Interface.h"
#include "Game/Game.h"

int	main()
{
	Game	game;
	Interface	interface(&game);
	interface.menu();
	return 0;
}
