#include "audioProcess.h"

AudioProcess::AudioProcess(std::string jackName)
{
  allpassFilters = new AllpassFilter*[2];

  allpass = new AllpassFilter(8000);
  allpass1 = new AllpassFilter(6000);

  process();

  jack.init(jackName);
  jack.autoConnect();

}

AudioProcess::~AudioProcess()
{
  delete allpass;
  allpass= nullptr;
  delete allpass1;
  allpass1 = nullptr;
}

void AudioProcess::switchF(int s)
{
    this->s=s;
}

void AudioProcess::process()
{
  jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes, double samplerate) {

    for(int i = 0; i < nframes; i++) {
        double sample = inBuf[i];
        double allPs1 = allpass->process(sample) + allpass1->process(sample);
        outBuf[i] = allPs1 * 0.5;
    }
    return 0;
  };
}
