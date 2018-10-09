#include "controller.h"


void func_pinController(const void*X){
  ((Controller*)X)->pinController();
}
void func_comunication(const void*X){
  ((Controller*)X)->comunication();
}
void func_acquisition(const void*X){
  ((Controller*)X)->acquisitionr();
}

Controller::Controller(MODE mode, int port):
  serverCtrl(port),
  myMode(mode),
  enable(false),
  newData(false),
  temp(0),
  humid(0),
  gpio_LedEnable(PINS::LED_enable),
  pwm_LedSensor(PINS::LED_Sensor),
  pwm_LedPWM(PINS::LED_PWM),
  pwm_DriveFan(PINS::DRIVE_Fan),
  gpio_HumidSensor(PINS::SENSOR_Humid),
  gpio_Button(PINS::BUTTON),
  thr_acquisition(func_acquisition, (const void*)this),
  thr_pinController(func_pinController, (const void*)this),
  thr_comunication(func_comunication, (const void*)this)
{
  //configuracao dos pinos
  gpio_LedEnable.dir(mraa::DIR_OUT_LOW);
  gpio_HumidSensor.dir(mraa::DIR_OUT_LOW);
  gpio_Button.dir(mraa::DIR_IN);

  //habilita as saidas pwm
  pwm_LedPWM.enable(true);
  pwm_LedSensor.enable(true);
  pwm_DriveFan.enable(true);

}

void Controller::pinController(){

}

Controller::~Controller(){
  thr_acquisition.join();
  thr_pinController.join();
  thr_comunication.join();

  pwm_LedSensor.enable(false);
  pwm_LedPWM.enabe(false);
  pwm_DriveFan.enable(false);

  gpio_LedEnable.write(0);
  gpio_HumidSensor.dir(mraa::DIR_OUT_LOW);
}
