#ifndef _H_ALLPASS_
#define _H_ALLPASS_

#include <vector>
#include <iostream>
#include <thread>
#include "jack_module.h"


class Allpass
{
public:
  Allpass(int bufferSize);
  ~Allpass();
  float filterProcess(float signalIn);
  void audioProcess();
private:
  JackModule jack;

  int bufferSize;
  float signalOut;
  double samplerate = 44100;

  std::vector<double> delayBuffer;

  std::thread* audioThread;
};


#endif //_H_ALLPASS_
