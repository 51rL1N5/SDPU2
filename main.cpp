#include "controller.h"

int main(){
  int port = 300000;
  Controller ctrl_Fan(MODE::DEFAULT, port);
  ctrl_Fan.start();

  return 0;
}
