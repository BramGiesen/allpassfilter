#include <iostream>
#include <thread>
#include <stdlib.h>     /* strtol */

#include "jack_module.h"
#include "math.h"
#include "allpass.h"

#define PI_2 6.28318530717959



int main(int argc,char **argv)
{
  char * pOrder;
  long int order;

  if(argv[1] != nullptr){
    order = strtol (argv[1],&pOrder,10);
    if(order > 0){
        Allpass allpass(order);
    } else {
      std::cout << "please enter a number higher then 0" << std::endl;
    }
  } else {
    std::cout << "null" << std::endl;
  }

  std::cout << "\n\nPress 'q' when you want to quit the program.\n";

  bool running = true;
  while (running)
  {
    // allpass.audioProcess();
      switch (std::cin.get())
      {
          case 'q':
            running = false;
            break;
      }
  }

  return 0;
} // main()
