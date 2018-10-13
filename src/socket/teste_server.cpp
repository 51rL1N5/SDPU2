// #include "SocketException.h"
#include <string>
#include <iostream>

#include "socket4L.h"

int main ()
{
  ServerSocket server;
  ServerSocket newSock;
  std::string dataInput;

  server.create();
  server.bind(30000);

  std::cout << "running....\n";
  while(true){
    server.listen();
    server.accept(newSock);
    newSock >> dataInput;

    newSock << dataInput;
    newSock.disconnect();
  }

  return 0;
}
