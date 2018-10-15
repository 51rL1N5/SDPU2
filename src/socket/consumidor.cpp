#include <system_tools.h>
#include "socket4L.h"

#include <iostream>
#include <string>
#include <fstream>

#define timer_step 0.05 //segundos

int main()
{
  std::ofstream O("../../etc/dados");
  double valor;
  int curva;
  char ip[] = "192.168.0.26";
  int port = 28500;
  double tempo_limite;
  std::string resposta;


  ClientSocket client_socket ( ip, port);

  std::cout << "Escolha a curva: " << '\n';
  std::cout << "1- Curva Padrão" << '\n';
  std::cout << "2- Curva 2" << '\n';
  std::cin >> curva;

  switch (curva) {
    case 1:
      client_socket << "MODE_1";
      std::cout << "Curva 1 selecionada" << '\n';
      tempo_limite = 30;
    break;
    case 2:
      client_socket << "MODE_2";
      std::cout << "Curva 2 selecionada" << '\n';
      tempo_limite = 40;
    break;
    default:
      std::cerr << "Curva invalida" << '\n';
      client_socket << "stop";
      client_socket.disconnect();
      return 1;
  }
  std::cout << "Tempo limite:\t"<<tempo_limite << '\n';
  tools::sleep(0.3);
  client_socket.disconnect();
  client_socket.create();
  client_socket.connect(ip, port);
  client_socket << "start";

  std::cout << "Coletando dados..." << '\n';
  double start = tools::clock();
  while(true){

    client_socket.disconnect();
    client_socket.create();
    client_socket.connect(ip, port);
    client_socket << "request";
    client_socket >> resposta;
    valor = std::stod(resposta);
    O << (float)valor;
    O << ", ";

    if((tools::clock() - start ) > tempo_limite)
      break;

    tools::sleep(timer_step);
  }
  client_socket.disconnect();
  std::cout << "conexao encerrada..." << '\n';
  O << 0;
  O.close();

  return 0;
}
