#include "PowerPlant.h"

void PowerPlant::work(Resources& resources, int day, int n)
{
  (void) resources;
  (void) day;
  work_(n, resources.wood);
  resources.coal += coal;
  coal =0;
}

void PowerPlant::work_(int number_of_operators, int &wood)
{
  if (this->active && number_of_operators > 0 && (coal + 1)< max_coal && wood > 0)
  {
    wood--;
    this->coal += 1;
    // + energy
  }
}

int PowerPlant::sellAllResources()
{
  return coal;
}