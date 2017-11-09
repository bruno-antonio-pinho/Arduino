int SENSOR1, SENSOR2, SENSOR3;

//deslocamentos de calibracao
int leftOffset = 0, rightOffset = 0, centre = 0;
//pinos para a velocidade e direcao do motor
int speed1 = 3, speed2 = 11, direction1 = 12, direction2 = 13;
//velocidade inicial e deslocamento de rotacao
int startSpeed = 255, rotate = 30;
//limiar do sensor
int threshold = 30;
//velocidades iniciais dos motores esquerdo e direito
int left = startSpeed, right = startSpeed;

//Rotina de calibracao do sensor
void calibrate()
{
 for (int x=0; x<10; x++) //Executa 10 vezes para obter uma media
 {
   delay(100);
   SENSOR1 = analogRead(8);
   SENSOR2 = analogRead(9);
   SENSOR3 = analogRead(10);
   leftOffset = leftOffset + SENSOR1;
   centre = centre + SENSOR2;
   rightOffset = rightOffset + SENSOR3;
   delay(100);
 }
 //obtem a media para cada sensor
 leftOffset = leftOffset /10;
 rightOffset = rightOffset /10;
 centre = centre / 10;
 //calcula os deslocamentos para os sensores esquerdo e direito
 leftOffset = centre - leftOffset;
 rightOffset = centre - rightOffset;
}

void setup()
{
  //calibrate();
  delay(3000);
  Serial.begin(115200);
}

void loop()
{
  //utiliza a mesma velocidade em ambos os motores
    //left = startSpeed;
    //right = startSpeed;
    //Serial.println("Segue reto.");
    Serial.print("sensor 1: ");
    Serial.println(analogRead(8));
    Serial.print("sensor 2: ");
    Serial.println(analogRead(9));
    Serial.print("sensor 3: ");
    Serial.print(analogRead(10));
    Serial.println("\n ");

}

// testar saida dos sensores 

