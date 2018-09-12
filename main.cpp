#include <iostream>
#include "audioProcess.h"
#include "allpassFilter.h"

#define TICK 0

int main(int argc,char **argv)
{
  AudioProcess aProcess("jackServer1");


#if (TICK == 1)
  AllpassFilter afilter(8000);
  for(int i= 1; i < 17; i++){
    static int sample = 1;
    std::cout << i << " " << "sample = " << sample << "  " << afilter.process(sample) << std::endl;
    sample = 0;
}
#else
  bool running = true;
  if (running)
    std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  while (running)
  {
      switch (std::cin.get())
      {
          case 'q':
            running = false;
            break;
      }

    }
  #endif // TICK
  //end the program
  return 0;
} // main()
