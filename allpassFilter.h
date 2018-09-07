#ifndef _H_ALLPASSFILTER_
#define _H_ALLPASSFILTER_

#include <vector>

class AllpassFilter
{
public:
  AllpassFilter();
  ~AllpassFilter();
  void setFilter(float coeff);
  double process(double input);
private:
  double output = 0;
  double filterOutput = 0;
  std::vector<double> delayBuffer;
};

#endif //_H_ALLPASSFILTER_
