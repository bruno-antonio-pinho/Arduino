#ifndef _Seguidor_h_
#define _Seguidor_h_

#include<AFMotor.h>

class Seguidor{

  public:
    Seguidor(void);
    void move_linha( AF_DCMotor motor_esq, AF_DCMotor motor_dir, int direcao, int forca_frente, int forca_volta);

};

#endif
