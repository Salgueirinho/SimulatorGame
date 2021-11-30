#include <random>
#include "Forest.h"

Forest::Forest()
{
	std::mt19937	rng(std::random_device{}());
	std::uniform_int_distribution<int> gen(20, 40);
	trees = gen(rng);
}
