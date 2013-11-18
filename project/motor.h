
#ifndef __MOTOR_H__
#define __MOTOR_H__

#define MOTOR_FORWARD  (0x00)
#define MOTOR_BACKWARD (0x01)

void SetMotorSpeedLeft(unsigned char direction, unsigned char speed);

void SetMotorSpeedRight(unsigned char direction, unsigned char speed);

#endif /* __MOTOR_H__ */
