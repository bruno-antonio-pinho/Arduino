#include <Manual.h>
#include <Seguidor.h>
#include <AFMotor.h>

AF_DCMotor motor_L(1);
AF_DCMotor motor_R(2);

Manual manual_move;

Seguidor seguidor_linha;

int SENSOR1, SENSOR2, SENSOR3, media, direcao;

int cruz;
uint8_t msg[2];

//deslocamentos de calibracao
int leftOffset = 0, rightOffset = 0, centre = 0;

//forca dos motores
int forca_frente = 100;
int forca_volta = 100;

//limiar do sensor
int threshold = 80;

// tempo para identificacao perda de rota
unsigned long StartTime = 0;

//Rotina de calibracao do sensor
void calibrate() {
  SENSOR1 = 0;
  SENSOR2 = 0;
  SENSOR3 = 0;
  leftOffset = 0;
  centre = 0;
  rightOffset = 0;

  for (int x = 0; x < 10; x++) //Executa 10 vezes para obter uma media
  {

    SENSOR1 = analogRead(8);
    SENSOR2 = analogRead(9);
    SENSOR3 = analogRead(10);
    leftOffset = leftOffset + SENSOR1;
    centre = centre + SENSOR2;
    rightOffset = rightOffset + SENSOR3;
  }
  //obtem a media para cada sensor
  leftOffset = leftOffset / 10;
  rightOffset = rightOffset / 10;
  centre = centre / 10;

  media = (leftOffset + rightOffset + centre + SENSOR1 + SENSOR2 + SENSOR3) / 3;

}



void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  cruz = 0;
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  
  Serial.setTimeout(20);
  //////////////////////////////////////////////////////////////////////////////////////////////////////
  if (Serial.available()) {
    
    Serial.readBytes(msg, 2);

    if (msg[0] == 49) {
      //Serial.setTimeout(100);
      while (msg[0] != 48) {
        calibrate();
        //le os sensores e adiciona os deslocamentos
        SENSOR1 = analogRead(8) + leftOffset;
        SENSOR2 = analogRead(9) + centre;
        SENSOR3 = analogRead(10) + rightOffset;

        //direcao = 4 vira pra direita (esq = forward, dir = backward)
        //direcao = 5 vira pra esquerda (esq = backward, dir = forward)
        //direcao = diferente, para
        //deteccao cruzamento
        if (media > 1600) {
          Serial.println("Cruz");
          Serial.setTimeout(50);        
          Serial.readBytes(msg, 2);
          
          if (msg[1] == 68) {
            direcao = 4;
            seguidor_linha.move_linha(motor_L, motor_R, direcao, forca_frente, forca_volta);
            delay(600);
            while (SENSOR2 > (SENSOR1 + threshold) & SENSOR2 > (SENSOR3 + threshold) && media > 1000) {
              seguidor_linha.move_linha(motor_L, motor_R, direcao, forca_frente, forca_volta);
              calibrate();
            }
          }
          if (msg[1] == 69) {
            direcao = 5;
            seguidor_linha.move_linha(motor_L, motor_R, direcao, forca_frente, forca_volta);
            delay(600);
            while (SENSOR2 > (SENSOR1 + threshold) & SENSOR2 > (SENSOR3 + threshold) && media > 1000) {
              seguidor_linha.move_linha(motor_L, motor_R, direcao, forca_frente, forca_volta);
              calibrate();
            }
          }
          if (msg[1] == 70) {
            direcao = 2;
            seguidor_linha.move_linha(motor_L, motor_R, direcao, forca_frente, forca_volta);
            delay(600);
            while (SENSOR2 > (SENSOR1 + threshold) & SENSOR2 > (SENSOR3 + threshold) && media > 1000) {
              seguidor_linha.move_linha(motor_L, motor_R, direcao, forca_frente, forca_volta);
              calibrate();
            }
          }
          if (msg[1] == 88) {
            direcao = 8;
            seguidor_linha.move_linha(motor_L, motor_R, direcao, forca_frente, forca_volta);
            delay(600);
            while (SENSOR2 > (SENSOR1 + threshold) & SENSOR2 > (SENSOR3 + threshold) && media > 1000) {
              seguidor_linha.move_linha(motor_L, motor_R, direcao, forca_frente, forca_volta);
              calibrate();
            }
          }

        }

        //SEGUIR RETO
        if (SENSOR2 > (SENSOR1 + threshold) & SENSOR2 > (SENSOR3 + threshold) && media > 1000) {
          //Serial.println("RETO");
          direcao = 2;
          seguidor_linha.move_linha(motor_L, motor_R, direcao, forca_frente, forca_volta);
        }

        //Se SENSOR1 for maior do que o sensor do centro + limiar,
        // vire para a direita
        if (SENSOR1 > (SENSOR2 + threshold) & SENSOR1 > (SENSOR3 + threshold) && media > 1000) {
          //Serial.println("DIREITA");
          direcao = 1;
          seguidor_linha.move_linha(motor_L, motor_R, direcao, forca_frente, forca_volta);
        }

        //Se SENSOR3 for maior do que o sensor do centro + limiar,
        // vire para a esquerda
        if (SENSOR3 > (SENSOR2 + threshold) & SENSOR3 > (SENSOR1 + threshold) && media > 1000) {
          //Serial.println("ESQUERDA");
          direcao = 3;
          seguidor_linha.move_linha(motor_L, motor_R, direcao, forca_frente, forca_volta);
        }

        //direcao == 1 entao mantem pra direita
        //direcao == 2 entao volta
        //direcao == 3 entao mantem pra esquerda
        while (media < 1000) {          
          //Serial.println("FORA");
          seguidor_linha.move_linha(motor_L, motor_R, direcao, forca_frente, forca_volta);
          calibrate();
        //  if (StartTime > 4000) {
        //    seguidor_linha.move_linha(motor_L, motor_R, 8, forca_frente, forca_volta);
        //  }
        }
        Serial.readBytes(msg, 2);
      }
    }
    //delay(1000);
    //////////////////////////////////////////////////////////////////////////////////////////////////////

    //COMANDO MANUAL
    if (msg[0] == 48) {
      int dir = msg[1] - 48;
      int motor_speed = 98;
      manual_move.move_M(dir, motor_speed, motor_L, motor_R);
      delay(200);
      manual_move.move_M(dir, 0, motor_L, motor_R);
    }

  }

}
