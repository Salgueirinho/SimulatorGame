#include "Game.h"
#include "../errors/errors.h"

void	Game::list()
{

}

int	Game::list(int x, int y)
{
	if ((1 <= x && x <= island->getColumns())
			&& (1 <= y && y <= island->getRows()))
	{
		command_output = "Zone: \n" +
		"Building: \n" +
		"Workers: \n" +
		"Resources: \n";
	}
	else
		return COORDINATE_ERROR;
	return 0;
}
