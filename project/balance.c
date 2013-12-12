	
#include "motor.h"
#include "megatron.h"
#include "sensoric.h"
	
#define C_DIVISOR           (1)

#define NUM_INTEGRAL_VALUES (10)

volatile signed int wantedAngle = 0;

volatile signed int left = 0;
volatile signed int right = 0;
volatile signed long motorvalue = 0;
		
volatile signed long angle;
volatile signed long spin;

// adjustable here and in debugger
volatile signed int C_PROPORTIONAL = 4;
volatile signed int C_INTEGRAL = 1;
volatile signed int C_DIFFERENTIAL = 1;

signed int integralvalues[10];
int index = 0;

static signed int GetIntegralVal()
{
	signed int r = 0;
	int i = 0;
	for (i = 0; i < NUM_INTEGRAL_VALUES; i++) r += integralvalues[i];
	return (r / NUM_INTEGRAL_VALUES);
}

void BalanceInit()
{
	int i;
	for (i = 0; i < NUM_INTEGRAL_VALUES; i++)
	{
		integralvalues[i] = 0;
	}
}

void Balance()
{
	angle = GetCurrentAngle();
	spin = (angle - integralvalues[index]);//ReadSpinValue();
	
	integralvalues[index] = angle;
	index = (index + 1) % NUM_INTEGRAL_VALUES;

	motorvalue = 0;
	motorvalue += C_PROPORTIONAL * angle;
	motorvalue += C_DIFFERENTIAL * spin;
	motorvalue += C_INTEGRAL * GetIntegralVal();
	if (motorvalue > 255)
	  motorvalue = 255;
	if (motorvalue < -255)
	  motorvalue = -255;

	left = motorvalue;
	right = motorvalue;
	SetMotorSpeedsNoReturn(left, right);
}