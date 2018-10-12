#include "socket4L.h"

#include <iostream>
#include <string>

int main ()
{

  std::string resposta;
  std::string msg;

  while(true){
    ClientSocket client_socket ( "192.168.0.26", 30000 );
    std::cout << "msg: ";
    std::cin >> msg;
    client_socket << msg;
    client_socket >> resposta;
    std::cout << "Comando recebido: "<<resposta << '\n';
  }


  return 0;
}
