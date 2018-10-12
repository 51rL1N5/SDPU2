#include "controller.h"

int main(){
  int port = 300000;
  Controller ctrl_Fan(MODE::DEFAULT, port);
  ctrl_Fan.start();

  while(ctrl_Fan.inOperation()){
    //codigo paralelo ao controle
  };

  return 0;
}
