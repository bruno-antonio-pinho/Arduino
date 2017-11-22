#ifndef _Seguidor_h_
#define _Seguidor_h_

#include<AFMotor.h>

class Seguidor{

  public:
    Seguidor(void);
    void move_linha(AF_DCMotor motor_esq, AF_DCMotor motor_dir, int SENSOR1, int SENSOR2, int SENSOR3);

};

#endif
