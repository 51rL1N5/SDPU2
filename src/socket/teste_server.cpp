// #include "SocketException.h"
#include <string>
#include <iostream>
#include "socket4L.h"

int main ( int argc, int argv[] )
{
  std::cout << "running....\n";

  // Create the socket
  // ServerSocket server( 30000 );
  ServerSocket server2;

  server2.create();
  server2.bind(30000);
  server2.listen();

  ServerSocket newSock;
  server2.accept(newSock);

  std::string data;
  newSock >> data;
  std::cerr << "Dado recebido: "<< data << '\n';
  newSock << std::string("Mahoe!");

  return 0;
}
