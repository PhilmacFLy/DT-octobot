
#include "XE16xREGS.H"

#include "CCU60.H"
#include "IO.H"
#include "motor.h"

// API for Left Motor
void SetMotorSpeedLeft(unsigned char direction, unsigned char speed)
{
  CCU60_vLoadChannelShadowRegister(CCU60_CHANNEL_0, (0xFF - speed));
  CCU60_vEnableShadowTransfer(CCU60_TIMER_12);
  // rechter motor direction pin = 0 für vorwärts
  if (MOTOR_FORWARD == direction)
  {
    P4_OUT_P4 = 1;
  }
  else
  {
    P4_OUT_P4 = 0;
  }
}

// API for Right Motor
void SetMotorSpeedRight(unsigned char direction, unsigned char speed)
{
  CCU60_vLoadChannelShadowRegister(CCU60_CHANNEL_1, (0xFF - speed));
  CCU60_vEnableShadowTransfer(CCU60_TIMER_12);
  // rechter motor direction pin = 1 für vorwärts
  if (MOTOR_FORWARD == direction)
  {
    P4_OUT_P6 = 0;
  }
  else
  {
    P4_OUT_P6 = 1;
  }
}
