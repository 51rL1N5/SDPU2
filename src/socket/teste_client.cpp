#include "socket4L.h"
// #include "SocketException.h"
#include <iostream>
#include <string>

int main ( int argc, int argv[] )
{

  ClientSocket client_socket ( "192.168.0.20", 30000 );

  std::string dado;

  client_socket << "Test message.";

  client_socket >> dado;
  std::cout << "Dado recebido do servidor: "<< dado << '\n';

  return 0;
}
