
#include "XE16xREGS.H"

#include "ADC0.H"

#include "sensoric.h"

volatile unsigned int speed_spin = 0;
volatile unsigned int accel_x = 0;
volatile unsigned int accel_y = 0;
volatile unsigned int accel_z = 0;

void ReadSensorData()
{
   // read ALL! the ADC channels
   //13,14,5 for gyro acceleration
   //7 for spinning sensor
   //register 0 - channel 5  (Acceleration Z Axix)
   //register 1 - channel 6  (Acceleration Spinning)
   //register 2 - channel 7  (unused)
   //register 3 - channel 13 (Acceleration )
   //register 4 - channel 14 ()
   //register 5 - channel 15 (unused)
   ADC0_vStartSeq0ReqChNum(0, 0, 0, ADC0_ANA_5);
   ADC0_vStartSeq2ReqChNum(0, 0, 0, ADC0_ANA_13);
   while(!ADC0_uwResultValid(RESULT_REG_0) && !ADC0_uwResultValid(RESULT_REG_3)); // necessary?
   ADC0_vStartSeq0ReqChNum(0, 0, 0, ADC0_ANA_6);
   ADC0_vStartSeq2ReqChNum(0, 0, 0, ADC0_ANA_14);
   while(!ADC0_uwResultValid(RESULT_REG_1) && !ADC0_uwResultValid(RESULT_REG_4)); // necessary?
   //ADC0_vStartSeq0ReqChNum(0, 0, 0, ADC0_ANA_7);
   //ADC0_vStartSeq2ReqChNum(0, 0, 0, ADC0_ANA_15);  
   //while(!ADC0_uwResultValid(RESULT_REG_2) && !ADC0_uwResultValid(RESULT_REG_5)); // necessary?

   accel_x = ADC0_uwGetResultData(RESULT_REG_3);
   accel_y = ADC0_uwGetResultData(RESULT_REG_4);
   accel_z = ADC0_uwGetResultData(RESULT_REG_0);
   speed_spin = ADC0_uwGetResultData(RESULT_REG_1);
}

unsigned char ReadAccelValueRaw(unsigned char direction)
{									   
  if (direction == DIRECTION_X) return ((unsigned char) (accel_x >> 2));
  if (direction == DIRECTION_Y) return ((unsigned char) (accel_y >> 2));
  if (direction == DIRECTION_Z) return ((unsigned char) (accel_z >> 2));
  return 0;
}
  
unsigned char ReadSpinValueRaw()
{
  return ((unsigned char) (speed_spin >> 2));
} 

// untested
//DIRECTION_X positive value: backward, negative value: forward
//DIRECTION_Y positive value: left, negative value: right
//DIRECTION_Z positive value: down, negative value: up
signed int ReadAccelValue(unsigned char direction)
{
  unsigned int tmp = 0;
  signed int x;

  if (direction == DIRECTION_X) tmp = accel_x;
  if (direction == DIRECTION_Y) tmp = accel_y;
  if (direction == DIRECTION_Z) tmp = accel_z;

  // 0 - 0x3FF / 0 - 1023, voltage is irrelevant because Vs = Vref
  // 511/512 is middle
  if (tmp < 512) x = - ( (signed int) (511 - tmp) ); // <= 511 is negative
  else           x =   ( (signed int) (tmp - 512) ); // >= 512 is positive
  
  // at Vs = 3,3V, the sensitivity is about 330mV / g
  // therefore, -511 to 511 is similar to -5G - +5G
  return ((x * 1000) / 1022); // return value * 0,01g = X g
}

// untested
// positive value: vorwärts kipping
// negative value: rückwärts kipping
signed int ReadSpinValue()
{
  unsigned int tmp = speed_spin;
  signed int x;

  // 0 - 0x3FF / 0 - 1023, voltage is irrelevant because Vs = Vref
  // 511/512 is middle
  if (tmp < 512) x = - ( (signed int) (511 - tmp) ); // <= 511 is negative
  else           x =   ( (signed int) (tmp - 512) ); // >= 512 is positive

  // at Vs = 3,3V the sensitivity is about 3,3mV / °/s
  // therefore, -511 to 511 is similar to -500°/s - +500°/s
  return (( x * 1000) / 1022); // return value = X°/s
}
