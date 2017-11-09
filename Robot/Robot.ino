#include<Manual.h>
#include <AFMotor.h>
 
AF_DCMotor motor_L(2);
AF_DCMotor motor_R(1);
Manual manual_move;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }  
}

void loop() {
   if (Serial.available()) {
    Serial.println("Estou aqui: ");
    int dir = Serial.read();
    int motor_speed = Serial.read();
    manual_move.move_M(dir, motor_speed, motor_L, motor_R);
  }

}
