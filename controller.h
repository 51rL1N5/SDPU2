//*** CLASSE PRINCIPAL ***//
#include <thread> // std::thread
#include <sys/time.h> //timeval

#include <mraa/commom.hpp>
#include <mraa/gpio.hpp>
#include <mraa/pwm.hpp>

#include <socket4L.h> //class Socket_4Linux
#include <system_tools.h>
// Modos de operacao
// Defininem o comportamento do secador de graos
enum MODE{
  DEFAULT,//gera a curva padrao
  MODE1,  //igual ao modo Default
  MODE2
  // ...
};

class Controller
// public Socket,
// public Acquisition
{
  //ver multex
private:
  ServerSocket serverCtrl;
  MODE myMode;
  bool enable;  //Flag para ativar/desativar o sistema, True: habilitado, False: desabilitado

  mraa::Gpio gpio_LedEnable;
  mraa::Gpio gpio_HumidSensor;
  mraa::Gpio gpio_Button;
  mraa::Pwm  pwm_LedSensor;
  mraa::Pwm  pwm_LedPWM;
  mraa::Pwm  pwm_DriveFan;

  std::atomic<bool> newData; //Ha dados dos sensores para serem lidos
  std::atomic<uint8_t> temp; //valor de temperatura em graus celcius
  std::atomic<uint8_t> humid;//valor da humidade relativade ( 0% ate 100%)


  // thread para leitura de dados
  std::thread thr_acquisition;
  //thread que realizara o contro dos pinos
  std::thread thr_pinController;
  //thread responsavel pelo recebimento e envio de dados
  std::thread thr_comunication;
  // std::thread thr_timer();//Analisar se realmente vai ser necessario

  //WARNING Nota: Usar a funcao da MRAA para interrupcao: isr(...). ver a documentacao.
  //Funcao que sera associada a interrupcao do botao
  void botton_interrupt();

  enum PINS{
    LED_enable,  // Pino do led para indicar o estados do sistema: ON/OFF
    LED_Sensor,  // Pino do Led associado a a leitura de um dos sensores
    LED_PWM,     // Pino do Led associado ao PWM enviado ao drive do motor
    BUTTON,      // Pino associado ao botao
    DRIVE_Fan,   // Pino para PWM do motor
    SENSOR_Humid,// Pino para leitura AD do sensor de umidade
    Sensor_Temp  // Pino para leitura AD do sensor de temperatura
  };

  //Funcoes que ditam o comportamento da saida PWM para o motor
  //retornam o valor do PWM
  uint8_t curve(); //este eh o metodo que deve ser chamado para o retorno final(ele chaveia entre os demais, de acordo com o modo atual)
  uint8_t curve_1(); //curva padrao
  uint8_t curve_2(); //curva 2
  //Metodos para as threads:
  void pinController();
  void comunication();
  void acquisition();

  //Funcoes auxiliares(para permitir usar metodos nas threads)
  friend void func_pinController(const void*X);
  friend void func_comunication(const void*X);
  friend void func_acquisition(const void*X);
public:

  Controller(MODE mode = DEFAULT, int port = 300000);
  ~Controller();

  //Retorna o status do sistema
  inline bool inOperation()const {return  status;}
  //Aprincipio so sera usado por comandos via socket, logo n sera necessario este metodo para o main
  MODE getMode()const {return my_mode};
  void setMode(const MODE &new_mode);//Aprincipio so sera usado por comandos via socket, logo n sera necessario este metodo para o main
  //retoma o sistema da onde parou, ou inicia do zero
  void start();
  //Suspende o sistema temporariamente
  //ao ser religado com start(), o sistema retoma
  //da onde parou
  void stop();
  //desliga o sistemas
  void shutdown();
};
