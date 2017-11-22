#include "Seguidor.h"

Seguidor::Seguidor(void){
}

//Programa : Motor shield com sensor TCRT5000
//Adaptacoes : FILIPEFLOP
//
//Baseado no programa original de Michael McRoberts

void Seguidor::move_linha(AF_DCMotor motor_esq, AF_DCMotor motor_dir, int SENSOR1, int SENSOR2, int SENSOR3){

    
  //le os sensores e adiciona os deslocamentos
  //SENSOR1 = analogRead(8) + 200; //200 é o valor do offset
  //SENSOR2 = analogRead(9) + 200;
  //SENSOR3 = analogRead(10) + 200;

  int leftOffset = 200;
  int rightOffset = 200;

  // pra seguir reto
  if (SENSOR2 > SENSOR1 & SENSOR2 > SENSOR3){
      motor_esq.setSpeed(120);
      motor_esq.run(FORWARD);
      motor_dir.setSpeed(120);
      motor_dir.run(FORWARD);
  }

  //Se SENSOR3 for maior do que o sensor do centro + limiar,
// vire para a direita
  if ((SENSOR3) > (SENSOR1+leftOffset))
  {
    motor_esq.setSpeed(80);
    motor_esq.run(FORWARD);
    motor_dir.setSpeed(140);
    motor_dir.run(FORWARD);
  }

  //Se SENSOR1 for maior do que o sensor do centro + limiar,
// vire para a esquerda
  if ((SENSOR1) > (SENSOR3+rightOffset))
  {
    motor_esq.setSpeed(140);
    motor_esq.run(FORWARD);
    motor_dir.setSpeed(80);
    motor_dir.run(FORWARD);
  }

}


