#include <Manual.h>
#include <Seguidor.h>
#include <AFMotor.h>

AF_DCMotor motor_L(2);
AF_DCMotor motor_R(1);

int SENSOR1, SENSOR2, SENSOR3;

Manual manual_move;

Seguidor seguidor_linha;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  uint8_t msg[2];

  if (Serial.available()) {
    Serial.readBytes(msg, 2);


    if(msg[0] == 49){
      while(msg[0] != 48){             
        SENSOR1 = analogRead(8) + 200; //200 é o valor do offset
        SENSOR2 = analogRead(9) + 200;
        SENSOR3 = analogRead(10) + 200;
        seguidor_linha.move_linha(motor_L, motor_R, SENSOR1, SENSOR2, SENSOR3);
        Serial.readBytes(msg, 2);
      }
  }

      if (msg[0] == 48) {
      int dir = msg[1] - 48;
      int motor_speed = 148;
      manual_move.move_M(dir, motor_speed, motor_L, motor_R);
    }
    
}

}
