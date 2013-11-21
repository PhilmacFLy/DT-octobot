
#include "XE16xREGS.H"

#include "CCU60.H"
#include "IO.H"
#include "math.h"
#include "megatron.h"
#include "motor.h"

void SetMotorSpeeds(signed int* left_p, signed int* right_p)
{
  signed int left = *left_p;
  signed int right = *right_p;

  static signed int lastleft = 0;
  static signed int lastright = 0;

  unsigned long megatronleft;
  unsigned long megatronright;

  unsigned int optimusprimeleft;
  unsigned int optimusprimeright;

  // zu hohe werte abfangen
  if (left > 0xFF) left = 0xFF;
  if (left < -0xFF) left = -0xFF;
  if (right > 0xFF) right = 0xFF;
  if (right < -0xFF) right = -0xFF;

  // maximal speed um 25 aendern
  if (25 < abs(left - lastleft))
  {
    if (left > lastleft) left = lastleft + 25;
	else left = lastleft - 25;
  }
  if (25 < abs(right - lastright))
  {
    if (right > lastright) right = lastright + 25;
	else right = lastright - 25;
  }

	 
  // megatron auslesen
  megatronleft = ReadMegatronLeft();
  megatronright = ReadMegatronRight();
		
  // verhaeltnis der megatrons errechnen
  if (lastleft != 0) optimusprimeleft = megatronleft * 0xFF / abs(lastleft);
  else optimusprimeleft = 0;
  if (lastright != 0) optimusprimeright = megatronright * 0xFF / abs(lastright);
  else optimusprimeright = 0;

  // vor nachjustierung errechnete werte speichern
  lastleft = left;
  lastright = right;

  if (optimusprimeleft > 0 && optimusprimeright > 0)
  {
	if (optimusprimeleft > optimusprimeright) // links "schneller" als rechts
	{
	  // links langsamer drehen
	  left = left * ((signed int)	optimusprimeright) / ((signed int) optimusprimeleft);
	}
	if (optimusprimeright > optimusprimeleft) // rechts "schneller" als links
	{
	  // rechts langsamer drehen
      right = right * ((signed int) optimusprimeleft) / ((signed int) optimusprimeright);
	}
  }


  if (left < 0)
    SetMotorSpeedLeft(MOTOR_BACKWARD, abs(left));
  else
	SetMotorSpeedLeft(MOTOR_FORWARD, left); // kein abs noetig, da left>=0
  
  if (right < 0)
    SetMotorSpeedRight(MOTOR_BACKWARD, abs(right));
  else
    SetMotorSpeedRight(MOTOR_FORWARD, right); // kein abs noetig, da right>=0
  
  *left_p = left;
  *right_p = right;
}

// API for Left Motor
void SetMotorSpeedLeft(unsigned char direction, unsigned char speed)
{
  CCU60_vLoadChannelShadowRegister(CCU60_CHANNEL_0, (0xFF - speed)); // ?
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
  CCU60_vLoadChannelShadowRegister(CCU60_CHANNEL_1, (0xFF - speed)); // ?
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
