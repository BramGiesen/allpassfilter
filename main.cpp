#include <iostream>
#include "audioProcess.h"
#include "allpassFilter.h"

#define DEBUG 0

int main(int argc,char **argv)
{
  AudioProcess aProcess;

  AllpassFilter allpass;

  static int xx = 0;

  for (int i = -8; i < 1; i++){
    if(i == -8){
      xx = 1;
    }
    else{
      xx = 0;
    }
    double output = allpass.process(xx);

    #if (DEBUG == 1)
      std::cout << "xx = " << xx << std::endl;
      std::cout << "output = " << output << std::endl;
    #endif
  }

  bool running = false;
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
  //end the program
  return 0;
} // main()
