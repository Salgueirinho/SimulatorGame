#include "Worker.h"


Worker::Worker(int d)
{
  int d_temp = d;
  float temp;
  static int n = 0;
  _n = n++;
  int count = 0;
  while (d_temp != 0)
  {
    d_temp = d_temp / 10;
    ++count;
  }
  temp = (float)n + ((float) d/ std::pow(10, count));
  this->id = temp;
  this->hiring_day = d;
}

int Worker::getHiringDay() const
{
  return hiring_day;
}

int Worker::getMovesLeft() const
{
  return moves_left;
}

void Worker::changeMovesLeft() {
  if (moves_left == 1)
    moves_left = 0;
}