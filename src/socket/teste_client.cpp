#include "socket4L.h"

#include <iostream>
#include <string>

int main ()
{

  std::string resposta;
  std::string msg;
  std::string valor;
  while(true){
    ClientSocket client_socket ( "192.168.0.26", 28500);

    std::cout << "msg: ";
    std::cin >> msg;
    client_socket << msg;
    client_socket >> resposta;
    std::cout << "Resposta recebido: "<<resposta << '\n';

    if(msg == "request"){
      if(resposta == "OK"){
        client_socket >> valor;
        std::cout << "Retorno do request: "<< std::stod(valor) << '\n';
      }else
        std::cout << "Request Erro" << '\n';
    }

  }


  return 0;
}
