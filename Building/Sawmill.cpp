#include "Sawmill.h"

void Sawmill::work(Resources& resources, int day, int n)
{
  (void) resources;
  (void) day;
  work_(resources.wood, n);
  resources.wood_planks += wood_planks;
  wood_planks = 0;
}
void Sawmill::work_(int &wood, int number_of_operators)
{
  if (this->active && wood>=2 && number_of_operators >= 1)
  {
    wood -= 2;
    wood_planks++;
  }
}

int Sawmill::sellAllResources()
{
  return wood_planks * 2;
}