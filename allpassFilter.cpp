#include "allpassFilter.h"
#include <iostream>

AllpassFilter::AllpassFilter(int bufferSize) : delayBuffer(bufferSize)
{
  bufferIndex = bufferSize - 1;
  std::fill(delayBuffer.begin(), delayBuffer.end(), 0);
}

AllpassFilter::~AllpassFilter()
{

}

void AllpassFilter::setFilter(float coeff)
{
}

double AllpassFilter::process(double input)
{
  static int index = 0;

  output = delayBuffer[index] * coeff + input;
  filterOutput = coeff * output - delayBuffer[index];
  delayBuffer[index] = input;

  index = (index != bufferIndex) ? index + 1 : 0;

  return filterOutput;
}
