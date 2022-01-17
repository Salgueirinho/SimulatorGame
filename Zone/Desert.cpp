#include "Desert.h"

void Desert::work(Resources& resources, int day)
{

  if(getBuilding() != nullptr)
  {
    std::string building_type = getBuilding()->getType();
    if(building_type == "mnF")
    {
      getBuilding()->work(resources, day, getNumberOfWorkers('M'));
    }
    else if (building_type == "mnC")
    {
      getBuilding()->work(resources, day, getNumberOfWorkers('M'));
    }
    else if (building_type == "bat")
    {
      getBuilding()->work(resources, day, 0);
    }
    else if (building_type == "edX")
    {
      getBuilding()->work(resources, day, 0);
    }
    else if (building_type == "fun")
    {
      getBuilding()->work(resources, day, getNumberOfWorkers('O'));
    }
    else if (building_type == "cen")
    {
      getBuilding()->work(resources, day, getNumberOfWorkers('O'));
    }else if (building_type == "ser")
    {
      getBuilding()->work(resources, day, getNumberOfWorkers('O'));
    }
  }
}