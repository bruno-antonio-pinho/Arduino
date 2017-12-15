#include "Seguidor.h"

Seguidor::Seguidor(void){
}

//Programa : Motor shield com sensor TCRT5000
//Adaptacoes : FILIPEFLOP
//
//Baseado no programa original de Michael McRoberts

//direcao = 1 direita
//direcao = 2 reto
//direcao = 3 esquerda
//direcao = 4 cruzamento, vira para direita
//direcao = 5 cruzamento, vira para esquerda

void Seguidor::move_linha(AF_DCMotor motor_esq, AF_DCMotor motor_dir, int direcao, int forca_frente, int forca_volta){

  //SEGUIR RETO
  if (direcao == 2) {
    motor_esq.setSpeed(forca_frente);
    motor_esq.run(FORWARD);
    motor_dir.setSpeed(forca_frente);
    motor_dir.run(FORWARD);
    return;
  }

  //Se SENSOR1 for maior do que o sensor do centro + limiar,
  // vire para a direita
  if (direcao == 1) {
    motor_esq.setSpeed(forca_frente);
    motor_esq.run(FORWARD);
    motor_dir.setSpeed(0);
    motor_dir.run(FORWARD);
    return;
  }

  //Se SENSOR3 for maior do que o sensor do centro + limiar,
  // vire para a esquerda
  if (direcao == 3){
    motor_esq.setSpeed(0);
    motor_esq.run(FORWARD);
    motor_dir.setSpeed(forca_frente);
    motor_dir.run(FORWARD);
    return;
  }
  
  //cruzamento, vai pra direita
    if (direcao == 4){
    motor_esq.setSpeed(forca_frente);
    motor_esq.run(FORWARD);
    motor_dir.setSpeed(forca_volta);
    motor_dir.run(BACKWARD);
    return;
  }
  
  //cruzamento, vai pra esquerda
    if (direcao == 5){
    motor_esq.setSpeed(forca_volta);
    motor_esq.run(BACKWARD);
    motor_dir.setSpeed(forca_frente);
    motor_dir.run(FORWARD);
    return;
  }
  
    //cruzamento, volta um pouco
    if (direcao == 6){
    motor_esq.setSpeed(forca_frente);
    motor_esq.run(BACKWARD);
    motor_dir.setSpeed(forca_frente);
    motor_dir.run(BACKWARD);
    return;
  }
  
    motor_esq.setSpeed(0);
    motor_esq.run(FORWARD);
    motor_dir.setSpeed(0);
    motor_dir.run(FORWARD);
}


