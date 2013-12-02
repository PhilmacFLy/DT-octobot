
#include "XE16xREGS.H"

#include "ADC0.H"

#include "sensoric.h"

volatile unsigned int gyro_x = 0;
volatile unsigned int gyro_y = 0;
volatile unsigned int gyro_z = 0;
volatile unsigned int accel_spin = 0;
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
   accel_spin = ADC0_uwGetResultData(RESULT_REG_1);
}

unsigned int ReadAccelValueRaw(unsigned char direction)
{
  if (direction == DIRECTION_X) return accel_x;
  if (direction == DIRECTION_Y) return accel_y;
  if (direction == DIRECTION_Z) return accel_z;
  return 0;
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

  // read value between 0x00 and 0x3FF
  // 0x3FF = 5V
  // 0x00 = 0V
  // Vs = 3,3V => 675
  // Vs/2 = 1,65V => 338
  // 1g = 0,33V => ~67,5
  if (tmp < 338) x = -((signed int)(338 - tmp)); // negative
  else           x = ((signed int)(tmp - 338)); // posivite

  // range -338 to 338
  //       -5G  to 5G
  return ((x * 100) / 338); // return value / 20 = X G
}

// untested
// positive value: vorwärts kipping
// negative value: rückwärts kipping
signed int ReadSpinAccelValue()
{
  unsigned int tmp = accel_spin;
  signed int x;

  //Vs = 3,3V => 675
  //Vs/2 = 1,65V => 338
  //3,3 mV / grad/s
  if (tmp < 338) x = -((signed int)(338 - tmp)); // negative
  else           x = ((signed int)(tmp - 338)); // positive

  // range -338 to 338
  //       -500 grad/s to 500 grad/s
  return ((x * 100) / 338); // return value / 5 = X grad/s
}
