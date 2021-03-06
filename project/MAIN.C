//****************************************************************************
// @Module        Project Settings
// @Filename      MAIN.C
// @Project       balancebot.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE167F-96F66
//
// @Compiler      Keil
//
// @Codegenerator 2.2
//
// @Description   This file contains the project initialization function.
//
//----------------------------------------------------------------------------
// @Date          16.12.2013 19:04:44
//
//****************************************************************************

// USER CODE BEGIN (MAIN_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (MAIN_General,2)

#include "motor.h"
#include "megatron.h"
#include "sensoric.h"
#include "balance.h"
// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (MAIN_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (MAIN_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (MAIN_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,7)
volatile unsigned char timerevent = 0;	
  volatile signed int speed = 20;
// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (MAIN_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (MAIN_General,9)

// USER CODE END


//****************************************************************************
// @Function      void MAIN_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This function initializes the microcontroller.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          16.12.2013
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void MAIN_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  //   globally disable interrupts
  PSW_IEN        =  0;          


  ///  -----------------------------------------------------------------------
  ///  Configuration of the System Clock:
  ///  -----------------------------------------------------------------------
  ///  - VCO clock used, input clock is connected
  ///  - input frequency is 8,00 MHz
  ///  - system clock is 66.00 MHz

  MAIN_vUnlockProtecReg();     // unlock write security

  MAIN_vChangeFreq();          // load PLL control register

  //   -----------------------------------------------------------------------
  //   Initialization of the Peripherals:
  //   -----------------------------------------------------------------------

  //   initializes the Parallel Ports
  IO_vInit();

  //   initializes the General Purpose Timer Unit (GPT1)
  GPT1_vInit();

  //   initializes the General Purpose Timer Unit (GPT2)
  GPT2_vInit();

  //   initializes the Capture / Compare Unit 60 (CCU60)
  CCU60_vInit();

  //   initializes the Analog / Digital Converter  (ADC0)
  ADC0_vInit();


  //   -----------------------------------------------------------------------
  //   Initialization of the Bank Select registers:
  //   -----------------------------------------------------------------------


  // USER CODE BEGIN (Init,3)

  // USER CODE END

  MAIN_vLockProtecReg();       // lock write security

  //   globally enable interrupts
  PSW_IEN        =  1;          

} //  End of function MAIN_vInit


//****************************************************************************
// @Function      void MAIN_vUnlockProtecReg(void) 
//
//----------------------------------------------------------------------------
// @Description   This function makes it possible to write one protected 
//                register.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          16.12.2013
//
//****************************************************************************

// USER CODE BEGIN (UnlockProtecReg,1)

// USER CODE END

void MAIN_vUnlockProtecReg(void)
{
  uword uwPASSWORD;

    SCU_SLC = 0xAAAA;                   // command 0
    SCU_SLC = 0x5554;                   // command 1

    uwPASSWORD = SCU_SLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;

    SCU_SLC = 0x9600 | uwPASSWORD;      // command 2
    SCU_SLC = 0x0000;                   // command 3

} //  End of function MAIN_vUnlockProtecReg


//****************************************************************************
// @Function      void MAIN_vLockProtecReg(void) 
//
//----------------------------------------------------------------------------
// @Description   This function makes it possible to lock one protected 
//                register.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          16.12.2013
//
//****************************************************************************

// USER CODE BEGIN (LockProtecReg,1)

// USER CODE END

void MAIN_vLockProtecReg(void)
{
  uword uwPASSWORD;

    SCU_SLC = 0xAAAA;                   // command 0
    SCU_SLC = 0x5554;                   // command 1

    uwPASSWORD = SCU_SLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;

    SCU_SLC = 0x9600 | uwPASSWORD;      // command 2
    SCU_SLC = 0x1800;                   // command 3; new PASSWOR is 0x00

    uwPASSWORD = SCU_SLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;
    SCU_SLC = 0x8E00 | uwPASSWORD;      // command 4

} //  End of function MAIN_vLockProtecReg


//****************************************************************************
// @Function      void MAIN_vChangeFreq(void) 
//
//----------------------------------------------------------------------------
// @Description   This function is used to select the external crystal and
//                configure the system frequency to 80Mhz/66Mhz.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          16.12.2013
//
//****************************************************************************

// USER CODE BEGIN (ChangeFreq,1)

// USER CODE END

void MAIN_vChangeFreq(void)
{
  SCS_SwitchToHighPrecBandgap();

  //For application and internal application resets, the complete PLL configuration could be avoided
  //The entry from application resets and internal application reset is covered in the following differentiation
  //in int/ext clock in lock/unlocked state.

  if  ((SCU_PLLSTAT & 0x0004) == 0x0004)             // fR derived from Internal clock
        {
            //Normal startup state during boot and the clock
            //has to be in the next step configured on the external crystal
            //use XTAL/VCO, count XTAL clock

            SCS_StartXtalOsc(1);                     // Starts the crystal oscillator
            SCS_SwitchSystemClock(1);                // System clock is increased to target speed (80/66 MHz)

        }

  else                                               // fR derived from external crystal clock
        {
            if ((SCU_PLLSTAT & 0x1009) == 0x1009)    // fR derived from external crystal clock + VCO is locked
            {
               //usually after an application reset where clock need not be configured again.
               //check K2/P/N values and decide whether these values have to be adapted based on application needs.
               NOP();
               //usually the PLL losss of Lock TRAP schould be enabled here.
            }
            else                                     //fR derived from external crystal clock + VCO is not locked

            {
               //estimate the K1 value and the current frequency
               //reduce K2/P/N values in steps so that the frequency
               //jumps is limited to 20MHz or factor of 5 whichever is minimum
               NOP();
            }


        }

} //  End of function MAIN_vChangeFreq


//****************************************************************************
// @Function      void main(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the main function.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          16.12.2013
//
//****************************************************************************

// USER CODE BEGIN (Main,1)

// USER CODE END

void main(void)
{
  // USER CODE BEGIN (Main,2)
  signed int ret_left;
  signed int ret_right;
  volatile signed int gyrovalue;
  unsigned char ledvalue;
  volatile signed int winkel = 0.0;
  volatile signed int val_x;
  volatile signed int val_y;
  volatile signed int val_z;

  unsigned char counter = 0;
  unsigned char timebase = 20; // * 5 ms

  // USER CODE END

  MAIN_vInit();

  // USER CODE BEGIN (Main,3)

  BalanceInit();

  // USER CODE END

  while(1)
  {

   // USER CODE BEGIN (Main,4)
   while(0 == timerevent);
   timerevent = 0;

   counter--;
   if (counter == 0)
   {
   		counter = timebase;		   
	   ReadSensorData();
	   Balance();
	   
	   // start reading the data, they will be get then
	   
	   gyrovalue = ReadSpinValue();
	   winkel = GetCurrentAngle();
	   ledvalue = ReadSpinValueRaw();
	   val_x = ReadAccelValue(DIRECTION_X) + 512;
	   val_y = ReadAccelValue(DIRECTION_Y) + 512;
	   val_z = ReadAccelValue(DIRECTION_Z) + 512;
	   
	   P10_OUT_P7 = (gyrovalue > 35) ? 0 : 1;
	   P10_OUT_P6 =	(gyrovalue > 25) ? 0 : 1;
	   P10_OUT_P5 =	(gyrovalue > 15) ? 0 : 1;
	   P10_OUT_P4 =	(gyrovalue > 5) ? 0 : 1;
	   P10_OUT_P3 =	(gyrovalue < -5) ? 0 : 1;
	   P10_OUT_P2 =	(gyrovalue < -15) ? 0 : 1;
	   P10_OUT_P1 =	(gyrovalue < -25) ? 0 : 1;
	   P10_OUT_P0 =	(gyrovalue < -35) ? 0 : 1;
	   // do some kind of stuff
	   //ret_left = 00;
	   //ret_right = 00;
	   //SetMotorSpeeds(&ret_left, &ret_right);
	   
	
	   //SetMotorSpeedsNoReturn(links_p, rechts_p);
	   // faehrt vorw�rts hoffentlich
	   // und au langsam
	   //SetMotorSpeedsNoReturn(speed, speed);//20, 20);
	}
   // USER CODE END

  }

} //  End of function main



// USER CODE BEGIN (MAIN_General,10)

// USER CODE END

