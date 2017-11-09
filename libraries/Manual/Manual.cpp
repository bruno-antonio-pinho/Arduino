#include "Manual.h"

Manual::Manual(void){
}

void Manual::move_M(int dir, int motor_speed, AF_DCMotor motor_L, AF_DCMotor motor_R){
  if(dir == 0){
    move_MFW(motor_speed, motor_L, motor_R);
  }else if(dir == 1){
     move_MBW(motor_speed, motor_L, motor_R);
  }else if(dir == 2){
     move_ML(motor_speed, motor_L, motor_R);
  }else if(dir == 3){
     move_MR(motor_speed, motor_L, motor_R);
  }else{
    move_MS(motor_L, motor_R);
  }
}

void Manual::move_MFW(int motor_speed, AF_DCMotor motor_L, AF_DCMotor motor_R){
  motor_L.setSpeed(motor_speed);
  motor_R.setSpeed(motor_speed);
  motor_L.run(FORWARD);
  motor_R.run(FORWARD);
}

void Manual::move_MBW(int motor_speed, AF_DCMotor motor_L, AF_DCMotor motor_R){
  motor_L.setSpeed(motor_speed);
  motor_R.setSpeed(motor_speed);
  motor_L.run(BACKWARD);
  motor_R.run(BACKWARD);
}

void Manual::move_ML(int motor_speed, AF_DCMotor motor_L, AF_DCMotor motor_R){
  motor_R.setSpeed(motor_speed);
  motor_L.setSpeed(motor_speed);
  motor_L.run(FORWARD);
  motor_R.run(BACKWARD);
}

void Manual::move_MR(int motor_speed, AF_DCMotor motor_L, AF_DCMotor motor_R){
  motor_L.setSpeed(motor_speed);
  motor_R.setSpeed(motor_speed);
  motor_R.run(FORWARD);
  motor_L.run(BACKWARD);
}

void Manual::move_MS(AF_DCMotor motor_L, AF_DCMotor motor_R){
  motor_R.run(RELEASE);
  motor_L.run(RELEASE);
}
