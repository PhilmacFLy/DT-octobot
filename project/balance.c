	
#include "motor.h"
#include "megatron.h"
#include "sensoric.h"
	
#define NUM_INTEGRAL_VALUES (10)

volatile signed int wantedAngle = 0;

volatile signed int left = 0;
volatile signed int right = 0;
volatile signed long motorvalue = 0;
		
volatile signed long angle;
volatile signed long spin;

// adjustable here and in debugger
volatile signed int C_PROPORTIONAL = 30;
volatile signed int C_INTEGRAL = 2;
volatile signed int C_DIFFERENTIAL = 5;

volatile signed int C_DIVISOR = 6;

volatile signed int NIXTUWINKEL = 2;

signed int integralvalues[10];
int index = 0;

int someerrorhappened = 0;

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
	motorvalue = 0;
}

void Balance()
{
	angle = GetCurrentAngle();
	spin = (angle - integralvalues[index]);//ReadSpinValue();
	if ((angle <= NIXTUWINKEL) && (angle >= -NIXTUWINKEL)) angle = 0;
	//if ((angle <= NIXTUWINKEL && angle >= 0) || (angle >= -NIXTUWINKEL && angle <= 0)) angle = 0;
	//else angle += 3;
	//if (angle >= -1 && angle <= 0) angle = 0;
	
	integralvalues[index] = angle;
	index = (index + 1) % NUM_INTEGRAL_VALUES;

    if (angle >= 25 || angle <= -25) someerrorhappened = 1;
	if (angle <  5  && angle >  -5)  someerrorhappened = 0;
	if (someerrorhappened == 1)
	{
		SetMotorSpeedsNoReturn(0, 0, 25);
		return;
	}

	motorvalue = 0;
	motorvalue += C_PROPORTIONAL * angle;
	motorvalue += C_DIFFERENTIAL * spin;
	motorvalue += C_INTEGRAL * GetIntegralVal();
	//motorvalue /= C_DIVISOR;
	if (motorvalue > 255 * C_DIVISOR)
	  motorvalue = 255 * C_DIVISOR;
	if (motorvalue < -255 * C_DIVISOR)
	  motorvalue = -255 * C_DIVISOR;

	left = motorvalue / C_DIVISOR;
	right = motorvalue / C_DIVISOR;
	SetMotorSpeedsNoReturn(left, right, angle);
}