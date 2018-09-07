#include "allpassFilter.h"
#include <iostream>

AllpassFilter::AllpassFilter() : delayBuffer(8)
{
  std::fill(delayBuffer.begin(), delayBuffer.end(), 0);
}

AllpassFilter::~AllpassFilter()
{

}

void AllpassFilter::setFilter(float coeff)
{
}

//y[n] = 0.167772 (x[n] + y[n-8]) - x[n-8]
double AllpassFilter::process(double input)
{
  static int index = 0;
  static int feedback = 0;
  static float coeff = 0.167772;

  output = delayBuffer[index];
  feedback = feedback + output;
  delayBuffer[index] = input;
  index = (index + 1) % 8;

  filterOutput = coeff * (input + feedback) - output;

  return filterOutput;
}
