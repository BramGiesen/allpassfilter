#ifndef _H_AUDIOPROCESS_
#define _H_AUDIOPROCESS_

#include <iostream>
#include <thread>

#include "jack_module.h"
#include "allpassFilter.h"


class AudioProcess
{
public:
  AudioProcess();
  ~AudioProcess();
  void process();
private:
  JackModule jack;
  AllpassFilter allpass;
};

#endif // _H_AUDIOPROCESS_
