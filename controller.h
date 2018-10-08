                                                //*** CLASSE PRINCIPAL ***//
#include <thread> // std::thread
#include <sys/time.h> //timeval

#include "../system_tools.h"
#include "socket_linux.h" //class Socket_4Linux
#include "acquisition.h"

// Modos de operacao
// Defininem o comportamento do secador
enum MODE{
  DEFAULT,//gera a curva padrao
  MODE2,
  MODE3
  // ...
};

class Controller:
  public Socket_4Linux,
  public Acquisition
{
private:
  MODE my_mode;
  bool status;
  // thread para leitura de dados
  std::thread thr_acquisition();
  //thread responsavel pelo recebimento e envio de dados
  std::thread thr_comunication();
  std::thread thr_timer();//Analisar se realmente vai ser necessario

  //WARNING Nota: Usar a funcao da MRAA para interrupcao: isr(...). ver a documentacao.
  //Funcao que sera associada a interrupcao do botao
  void botton_interrupt();
public:

  Controller(MODE mode = DEFAULT);
  ~Controller();

  MODE getMode()const {return my_mode};
  void setMode(const MODE &mode);
  //retoma o sistema da onde parou, ou inicia do zero
  void start();
  //Suspende o sistema temporariamente
  //ao ser religado com start(), o sistema retoma
  //da onde parou
  void stop();
  //desliga o sistema
  void shutdown();
};
