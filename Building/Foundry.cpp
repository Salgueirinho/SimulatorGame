#include "Foundry.h"

void Foundry::work(Resources& resources, int day, int n)
{
  (void) day;
  work_(resources.coal, resources.iron, 1, n);
  resources.steel += steel;
  steel = 0;
}

void  Foundry::work_(int &coal, int &iron, int valid_neighbors, int number_of_operators)
{
  if (this->active && coal > 0 && iron > 0 && valid_neighbors && number_of_operators)
  {
    coal--;
    iron--;
    steel++;
  }
}

int Foundry::sellAllResources()
{
  return steel *2;
}