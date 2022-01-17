#include "IronMine.h"
#include <iostream>

void IronMine::levelUp()
{
  level++;
}

void IronMine::work(Resources& resources, int day, int n)
{
  (void) day;
  work_(n);
  resources.iron += iron;
  iron = 0;
}

void IronMine::work_(int number_of_miners)
{
  if (this->active && number_of_miners > 0 && (iron + 2 + this->level - 1)< max_iron)
  {
    this->iron += 2 + this->level - 1;
  }
}

int IronMine::sellAllResources()
{
  return iron;
}