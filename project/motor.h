
#ifndef __MOTOR_H__
#define __MOTOR_H__

#define MOTOR_FORWARD  (0x00)
#define MOTOR_BACKWARD (0x01)

extern volatile unsigned int leftspeed;
extern volatile unsigned int rightspeed;

void SetMotorSpeedsNoReturn(signed int left, signed int right);

void SetMotorSpeeds(signed int* left_p, signed int* right_p);

void SetMotorSpeedLeft(unsigned char direction, unsigned char speed);

void SetMotorSpeedRight(unsigned char direction, unsigned char speed);

#endif /* __MOTOR_H__ */
