
#include "XE16xREGS.H"

#include "CC2.H"
#include "IO.H"
#include "motor.h"

// API for Left Motor
void SetMotorSpeedLeft(unsigned char direction, unsigned char speed)
{
  CC2_vStopTmr(CC2_TIMER_7);
  CC2_vSetCCxReg(CC2_CC_16, (0xFF00 | (uword) (~speed)));
  //P2_OUT_P2
  CC2_vStartTmr(CC2_TIMER_7);
}

// API for Right Motor
void SetMotorSpeedRight(unsigned char direction, unsigned char speed)
{	 
  CC2_vStopTmr(CC2_TIMER_7);
  CC2_vSetCCxReg(CC2_CC_17, (0xFF00 | (uword) (~speed)));
  //P2_OUT_P5
  CC2_vStartTmr(CC2_TIMER_7);
}
