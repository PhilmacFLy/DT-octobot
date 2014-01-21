#include "XE16xREGS.H"

#include "ADC0.H"

#include "sensoric.h"

#include "MATH.H"

// min 3
#define NUM_SAMPLES 10

// zero value ~= 512
volatile unsigned int accel_x_arr[NUM_SAMPLES];
volatile unsigned int accel_y_arr[NUM_SAMPLES];
volatile unsigned int accel_z_arr[NUM_SAMPLES];
volatile unsigned int speed_spin_arr[NUM_SAMPLES];

volatile unsigned int accel_x = 0;
volatile unsigned int accel_y = 0;
volatile unsigned int accel_z = 0;	
volatile unsigned int speed_spin = 0;

unsigned int GetMediumValue(unsigned int* vals)
{
	unsigned int ret = 0;
	unsigned int max = 0x0000;
	unsigned int min = 0xFFFF;
	int i = 0;

	// iterate and save min/max values
	for (i = 0; i < NUM_SAMPLES; i++)
	{
	  ret += vals[i];
	  if (vals[i] > max) max = vals[i];
	  if (vals[i] < min) min = vals[i];
    }

	// remove min/max values
	ret -= min;
	ret -= max;
	return (ret/(NUM_SAMPLES-2));
}

void ReadSensorData()
{
   unsigned int i = 0;
   volatile unsigned int tmp;
   // read ALL! the ADC channels
   //13,14,5 for gyro acceleration
   //7 for spinning sensor
   //register 0 - channel 5  (Acceleration Z Axix)
   //register 1 - channel 6  (Acceleration Spinning)
   //register 2 - channel 7  (unused)
   //register 3 - channel 13 (Acceleration )
   //register 4 - channel 14 ()
   //register 5 - channel 15 (unused)
   for (i = 0; i < NUM_SAMPLES; i++)
   {
	   ADC0_vStartSeq2ReqChNum(0, 0, 0, ADC0_ANA_5);
	   while(!ADC0_uwResultValid(RESULT_REG_0)); // necessary?
	   ADC0_vStartSeq2ReqChNum(0, 0, 0, ADC0_ANA_6);
	   while(!ADC0_uwResultValid(RESULT_REG_1)); // necessary?
	   ADC0_vStartSeq2ReqChNum(0, 0, 0, ADC0_ANA_13);
	   while(!ADC0_uwResultValid(RESULT_REG_3)); // necessary?
	   ADC0_vStartSeq2ReqChNum(0, 0, 0, ADC0_ANA_14);
	   while(!ADC0_uwResultValid(RESULT_REG_4)); // necessary?
      
       /*
	   ADC0_vStartSeq0ReqChNum(0, 0, 0, ADC0_ANA_5);
	   ADC0_vStartSeq2ReqChNum(0, 0, 0, ADC0_ANA_13);
	   while(!ADC0_uwResultValid(RESULT_REG_0) && !ADC0_uwResultValid(RESULT_REG_3)); // necessary?
	   ADC0_vStartSeq0ReqChNum(0, 0, 0, ADC0_ANA_6);
	   ADC0_vStartSeq2ReqChNum(0, 0, 0, ADC0_ANA_14);
	   while(!ADC0_uwResultValid(RESULT_REG_1) && !ADC0_uwResultValid(RESULT_REG_4)); // necessary?
	   ADC0_vStartSeq0ReqChNum(0, 0, 0, ADC0_ANA_7);
	   ADC0_vStartSeq2ReqChNum(0, 0, 0, ADC0_ANA_15);  
	   while(!ADC0_uwResultValid(RESULT_REG_2) && !ADC0_uwResultValid(RESULT_REG_5)); // necessary?
	   */
	   accel_x_arr[i] = ADC0_uwGetResultData(RESULT_REG_3);
	   accel_y_arr[i] = ADC0_uwGetResultData(RESULT_REG_4);
	   accel_z_arr[i] = ADC0_uwGetResultData(RESULT_REG_0);
	   speed_spin_arr[i] = ADC0_uwGetResultData(RESULT_REG_1);//1);
   }
   accel_x = GetMediumValue(accel_x_arr);
   accel_y = GetMediumValue(accel_y_arr);
   accel_z = GetMediumValue(accel_z_arr);
   speed_spin = GetMediumValue(speed_spin_arr);
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

// positive: forward
// negative: backward
signed int GetCurrentAngle()
{
	signed int xvalue;
	double alpha;
	xvalue = ReadAccelValue(DIRECTION_X);
	alpha = acos(((double)xvalue) / 100.0);
	// pi/2 = grade
	// <pi/2 = kippen vorwarts
	// >pi/2 = kippen ruckwarts
	alpha = alpha * 180. / 3.14159; // rad to grad
	alpha = alpha - 90.; // offset
	alpha = -alpha; // vorzeichen
	return ((signed int)alpha);
}

// untested
//DIRECTION_X positive value: forward, negative value: backward
//DIRECTION_Y positive value: left, negative value: right
//DIRECTION_Z positive value: down, negative value: up
signed int ReadAccelValue(unsigned char direction)
{
  unsigned int tmp = 0;
  signed long x; // because of *1000

  if (direction == DIRECTION_X) tmp = (signed long) accel_x + 2;
  if (direction == DIRECTION_Y) tmp = (signed long) accel_y + 0;
  if (direction == DIRECTION_Z) tmp = (signed long) accel_z + 0;

  // 0 - 0x3FF / 0 - 1023, voltage is irrelevant because Vs = Vref
  // 511/512 is middle
  if (tmp < 512) x = - ( (signed long) (511 - tmp) ); // <= 511 is negative
  else           x =   ( (signed long) (tmp - 512) ); // >= 512 is positive
  
  // at Vs = 3,3V, the sensitivity is about 330mV / g
  // therefore, -511 to 511 is similar to -5G - +5G
  return (signed int)((x * 1000) / 1022); // return value * 0,01g = X g
}

// tested
// positive value: r�ckwaerts kipping
// negative value: vorwaerts kipping
signed int ReadSpinValue()
{
  unsigned int tmp = speed_spin;
  signed int x; // because of *1000

  // 0 - 0x3FF / 0 - 1023, voltage is irrelevant because Vs = Vref
  // 511/512 is middle
  if (tmp < 512) x = - ( (signed int) (511 - tmp) ); // <= 511 is negative
  else           x =   ( (signed int) (tmp - 512) ); // >= 512 is positive

  // 40 mV offset (1,61V center, should be 1,65V)
  // 3,6 mV sensitivity =>  12-14
  x += 12;

  // at Vs = 3,3V the sensitivity is about 3,3mV / grad/s
  // therefore, -511 to 511 is similar to -500grad/s - +500grad/s
  return (signed int)(( -x * 1000) / 1022); // return value = Xgrad/s
}
