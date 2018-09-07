#include "audioProcess.h"

AudioProcess::AudioProcess()
{
  process();
  jack.init("audioProcess");
  jack.autoConnect();

}

AudioProcess::~AudioProcess()
{

}

void AudioProcess::process()
{
  jack.onProcess = [](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes, double samplerate) {

    for(int i = 0; i < nframes; i++) {
      outBuf[i] = inBuf[i];
    }
    return 0;
  };
}
