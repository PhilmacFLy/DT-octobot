
#include "XE16xREGS.H"

#include "CCU60.H"
#include "IO.H"
#include "math.h"
#include "megatron.h"
#include "motor.h"

unsigned int MAX_ACCELERATION = 40;

volatile unsigned int megatroncounter = 0;
volatile unsigned int megatronleft = 0;
volatile unsigned int megatronright = 0;
		   
volatile unsigned int optimusprimeleft;
volatile unsigned int optimusprimeright;

volatile unsigned int leftspeed = 0;
volatile unsigned int rightspeed = 0;

volatile signed long winkel = 0;

void SetMotorSpeedsNoReturn(signed int left, signed int right, signed long winkel)
{
  SetMotorSpeeds(&left, &right, winkel);
}

void SetMotorSpeeds(signed int* left_p, signed int* right_p, signed long winkel)
{
  signed int left = *left_p;
  signed int right = *right_p;

  static signed int lastleft = 0;
  static signed int lastright = 0;
//  winkel += 8;
  // zu hohe werte abfangen
  if (left > 0xFF) left = 0xFF;
  if (left < -0xFF) left = -0xFF;
  if (right > 0xFF) right = 0xFF;
  if (right < -0xFF) right = -0xFF;
  //if (winkel == 0) winkel = 10;
  // maximal speed um MAX_ACCELERATION aendern
 // maximal speed um 25 aendern
  if (MAX_ACCELERATION < abs(left - lastleft))
  {
    if (left > lastleft) left = lastleft + winkel;
	else left = lastleft - MAX_ACCELERATION;
  }
  if (MAX_ACCELERATION < abs(right - lastright))
  {
    if (right > lastright) right = lastright + winkel;
	else right = lastright - MAX_ACCELERATION;
  }
   
  // megatron auslesen alle 10 cycles
  megatroncounter = (megatroncounter + 1);
  if (megatroncounter == 10)
  {
	megatronleft = ReadMegatronLeft();
	megatronright = ReadMegatronRight();
	megatroncounter = 0;
  }

  // muss evtl angepasst werden		
  // verhaeltnis der megatrons errechnen
  if (lastleft != 0) optimusprimeleft = megatronleft * 0x10 / abs(lastleft);
  else optimusprimeleft = 0;
  if (lastright != 0) optimusprimeright = megatronright * 0x10 / abs(lastright);
  else optimusprimeright = 0;

  // vor nachjustierung errechnete werte speichern
  lastleft = left;
  lastright = right;

  if (optimusprimeleft > 0 && optimusprimeright > 0)
  {
	if (optimusprimeleft > optimusprimeright) // links "schneller" als rechts
	{
	  // links langsamer drehen
	  left = left * ((signed int) optimusprimeright) / ((signed int) optimusprimeleft);
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
  leftspeed = speed;
  CCU60_vLoadChannelShadowRegister(CCU60_CHANNEL_0, (0xFF - speed)); // ?
  CCU60_vEnableShadowTransfer(CCU60_TIMER_12);
  // rechter motor direction pin = 0 für vorwärts
  if (MOTOR_FORWARD == direction)
  {
    P4_OUT_P4 = 0;
  }
  else
  {
    P4_OUT_P4 = 1;
  }
}

// API for Right Motor
void SetMotorSpeedRight(unsigned char direction, unsigned char speed)
{
  rightspeed = speed;
  CCU60_vLoadChannelShadowRegister(CCU60_CHANNEL_1, (0xFF - speed)); // ?
  CCU60_vEnableShadowTransfer(CCU60_TIMER_12);
  // rechter motor direction pin = 1 für vorwärts
  if (MOTOR_FORWARD == direction)
  {
    P4_OUT_P1 = 1;
  }
  else
  {
    P4_OUT_P1 = 0;
  }
}
