#include "allpass.h"

Allpass::Allpass(int bufferSize) : bufferSize(bufferSize), delayBuffer(bufferSize)
{
  for (int index = 0; index < bufferSize; index++){
    delayBuffer[index] = 0;
  }

  this->bufferSize = bufferSize;

  audioProcess();
  jack.init("allpass");
  jack.autoConnect();
  samplerate = (float)jack.getSamplerate();

  std::thread audioThread(audioProcess);
}

Allpass::~Allpass()
{
  audioThread.join();

}

float Allpass::filterProcess(float signalIn)
{
  //y[n] = 0.167772 (x[n] + y[n-8]) - x[n-8]
  static float coef = 0.167772;
  static int index = 0;
  signalOut = coef * (signalIn + delayBuffer[bufferSize]) - delayBuffer[bufferSize];
  delayBuffer[index] = signalOut;
  index = (index + 1) % bufferSize;
  std::cout << "index = " << index << std::endl;

  return signalOut;
}

void Allpass::audioProcess()
{
  //assign a function to the JackModule::onProces
 jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
   jack_default_audio_sample_t *outBuf, jack_nframes_t nframes, double samplerate) {

     for(int i = 0; i < nframes; i++) {
       float filterSignal = filterProcess(inBuf[i]);
       outBuf[i] = filterSignal;
     }
     return 0;
   };
}
