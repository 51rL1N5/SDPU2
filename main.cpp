#include "controller.h"

#include <iostream>

int main(){
  // int port = 300000;
  Controller ctrl_Fan;
  ctrl_Fan.start();
  std::cout << "Sistema online" << '\n';
  while(ctrl_Fan.inOperation()){
    //codigo paralelo ao controle
  };
  std::cout << "Sistema finalizado" << '\n';

  return 0;
}
