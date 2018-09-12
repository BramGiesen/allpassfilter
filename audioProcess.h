#ifndef _H_AUDIOPROCESS_
#define _H_AUDIOPROCESS_

#include <iostream>
#include <thread>
#include <string>

#include "jack_module.h"
#include "allpassFilter.h"


class AudioProcess
{
public:
  AudioProcess(std::string jackName);
  ~AudioProcess();
  void process();
  void switchF(int s);
private:
  int s = 2;

  JackModule jack;
  AllpassFilter **allpassFilters;
  AllpassFilter *allpass;
  AllpassFilter *allpass1;
};

#endif // _H_AUDIOPROCESS_
