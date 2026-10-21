// qt_shared_deque_2.cpp
#include <iostream>
#include <limits>
#include <cassert>

#include "shared_ring_buffer.h"

int main(int argc, char *argv[])
{
  SharedRingBuffer<int> buffer;

  buffer.create(100);

  while(true){
    int value;
    std::cout << "$>";

    if(!(std::cin >> value)){
      if(std::cin.eof()){
        break;
      }
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Not a number, try again" << std::endl;
      continue;
    }

    if(!buffer.enqueue(value)){
      std::cout << "Buffer full, could not enqueue " << value << std::endl;
      break;
    }

    std::cout << "Enqueued: " << value << std::endl;
  }

  return 0;
}
