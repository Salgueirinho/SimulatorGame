#include "Battery.h"

void Battery::levelUp()
{
  this->level++;
}

void Battery::work(Resources& resources, int day, int n)
{
  (void) resources;
  (void) day;
  (void) n;
}

void Battery::work_(const int energy)
{
  if (this->active && (electricity + energy ) < max_electricity)
  {
    electricity += energy;
  }
}

int Battery::sellAllResources()
{
  return electricity * 2;
}