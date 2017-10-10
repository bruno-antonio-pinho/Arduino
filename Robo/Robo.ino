
#include <AFMotor.h>
 
AF_DCMotor motor_L(3);
AF_DCMotor motor_R(4);

void move_M(int dir, int motor_speed); // Move conforme a direção escolhida.
void move_MFW(int motor_speed); // Move o robô para frente.
void move_MBW(int motor_speed); // Move o robô para tras.
void move_ML(int motor_speed); // Move o robô para a esquerda.
void move_MR(int motor_speed); // Move o robô para a direita.
void move_MS(); // Para a movimentação do robô.

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }  
}

void loop() { // run over and over
  int dir = 0;
  int motor_speed = 50;
  
  /*if (Serial.available()) {
    dir = Serial.read();
    move_M(dir, motor_speed);
  } */

  move_M(0, 255);
  delay(5000);
  move_M(1, 255);
  delay(5000);
  move_M(2, 255);
  delay(5000);
  move_M(3, 255);
  delay(5000);
  move_M(4, 255);
  delay(5000);
  
}

void move_M(int dir, int motor_speed){
  if(dir == 0){
    move_MFW(motor_speed);
  }else if(dir == 1){
     move_MBW(motor_speed);
  }else if(dir == 2){
     move_ML(motor_speed);
  }else if(dir == 3){
     move_MR(motor_speed);
  }else{
    move_MS();
  }
}

void move_MFW(int motor_speed){
  motor_L.setSpeed(motor_speed);
  motor_R.setSpeed(motor_speed);
  motor_L.run(FORWARD);
  motor_R.run(FORWARD);
}

void move_MBW(int motor_speed){
  motor_L.setSpeed(motor_speed);
  motor_R.setSpeed(motor_speed);
  motor_L.run(BACKWARD);
  motor_R.run(BACKWARD);
}

void move_ML(int motor_speed){
  motor_R.setSpeed(motor_speed);
  motor_L.setSpeed(motor_speed);
  motor_L.run(FORWARD);
  motor_R.run(BACKWARD);
}

void move_MR(int motor_speed){
  motor_L.setSpeed(motor_speed);
  motor_R.setSpeed(motor_speed);
  motor_R.run(FORWARD);
  motor_L.run(BACKWARD);
}

void move_MS(){
  motor_R.run(RELEASE);
  motor_L.run(RELEASE);
}
