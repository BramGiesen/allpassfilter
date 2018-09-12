#ifndef _H_ALLPASSFILTER_
#define _H_ALLPASSFILTER_

#include <vector>

class AllpassFilter
{
public:
  AllpassFilter(int bufferSize);
  ~AllpassFilter();
  void setFilter(float coeff);
  double process(double input);
private:
  int bufferSize;
  int bufferIndex;
  double output = 0;
  double filterOutput = 0;
  std::vector<double> delayBuffer;
  float coeff = 0.167772;
};

#endif //_H_ALLPASSFILTER_
