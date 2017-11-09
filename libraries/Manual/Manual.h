#ifndef _Manual_h_
#define _Manual_h_

#include<AFMotor.h>

class Manual{

  public:
    Manual(void);
    void move_M(int dir, int motor_speed, AF_DCMotor motor_L, AF_DCMotor motor_R); // Move conforme a direção escolhida.
    void move_MFW(int motor_speed, AF_DCMotor motor_L, AF_DCMotor motor_R); // Move o robô para frente.
    void move_MBW(int motor_speed, AF_DCMotor motor_L, AF_DCMotor motor_R); // Move o robô para tras.
    void move_ML(int motor_speed, AF_DCMotor motor_L, AF_DCMotor motor_R); // Move o robô para a esquerda.
    void move_MR(int motor_speed, AF_DCMotor motor_L, AF_DCMotor motor_R); // Move o robô para a direita.
    void move_MS(AF_DCMotor motor_L, AF_DCMotor motor_R); // Para a movimentação do robô.
};

#endif
