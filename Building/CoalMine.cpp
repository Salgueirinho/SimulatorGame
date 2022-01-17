#include "CoalMine.h"

void CoalMine::levelUp()
{
  level++;
}

void CoalMine::work(Resources& resources, int day, int n)
{
  (void) day;
  work_(n);
  resources.coal += coal;
  coal = 0;
}

void CoalMine::work_(int number_of_miners)
{
  if (this->active && number_of_miners > 0 && (coal + 2 + this->level - 1)< max_coal)
  {
    this->coal += 2 + this->level - 1;
  }
}

int CoalMine::sellAllResources()
{
  return coal;
}