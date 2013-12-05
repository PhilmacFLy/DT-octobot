//****************************************************************************
// @Module        Parallel Ports
// @Filename      IO.C
// @Project       balancebot.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE167F-96F66
//
// @Compiler      Keil
//
// @Codegenerator 2.2
//
// @Description   This file contains functions that use the IO module.
//
//----------------------------------------------------------------------------
// @Date          05.12.2013 12:52:42
//
//****************************************************************************

// USER CODE BEGIN (IO_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (IO_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (IO_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (IO_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (IO_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (IO_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (IO_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (IO_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (IO_General,9)

// USER CODE END


//****************************************************************************
// @Function      void IO_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the IO function 
//                library. It is assumed that the SFRs used by this library 
//                are in reset state. 
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          05.12.2013
//
//****************************************************************************

// USER CODE BEGIN (IO_Function,1)

// USER CODE END

void IO_vInit(void)
{
  // USER CODE BEGIN (IO_Function,2)

  // USER CODE END


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P0:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P0 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P1:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P1 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P2:
  ///  -----------------------------------------------------------------------
  ///  P2.2 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P2.5 is used as general input
  ///  - pull device is tristate 

  ///  P2.0 - P2.3 output driver characteristic: strong driver
  ///  P2.4 - P2.7 output driver characteristic: strong driver
  ///  P2.8 - P2.12 output driver characteristic: strong driver

  ///  P2.0 - P2.3 output edge characteristic: sharp edge mode
  ///  P2.4 - P2.7 output edge characteristic: sharp edge mode
  ///  P2.8 - P2.12 output edge characteristic: sharp edge mode

  P2_IOCR02      =  0x0080;      // load port control register 2

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P3:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P3 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P4:
  ///  -----------------------------------------------------------------------
  ///  P4.0 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P4.1 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P4.3 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P4.4 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P4.6 is used as alternate input for the GPT12E  timer4Count input(T4IN)

  ///  P4.0 - P4.3 output driver characteristic: strong driver
  ///  P4.4 - P4.7 output driver characteristic: strong driver

  ///  P4.0 - P4.3 output edge characteristic: sharp edge mode
  ///  P4.4 - P4.7 output edge characteristic: sharp edge mode

  P4_IOCR00      =  0x0080;      // load port control register 0
  P4_IOCR01      =  0x0080;      // load port control register 1
  P4_IOCR03      =  0x0080;      // load port control register 3
  P4_IOCR04      =  0x0080;      // load port control register 4

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P5:
  ///  -----------------------------------------------------------------------
  ///  P5.0 is used as alternate input for the  Analog Input Pin (AN50)
  ///  P5.3 is used as alternate input for the  GPT12E Timer2 Count 
  ///  input(T3IN)
  ///  P5.5 is used as alternate input for the  Analog Input Pin (AN55)
  ///  P5.6 is used as alternate input for the  Analog Input Pin (AN56)
  ///  P5.7 is used as alternate input for the  Analog Input Pin (AN57)
  ///  P5.13 is used as alternate input for the  Analog Input Pin (AN513)
  ///  P5.14 is used as alternate input for the  Analog Input Pin (AN514)
  ///  P5.15 is used as alternate input for the  Analog Input Pin (AN515)


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P6:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P6 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P7:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P7 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P8:
  ///  -----------------------------------------------------------------------
  ///  P8.0 is used as alternate output for the  CCU60 output(CC60)
  ///  - push/pull output is selected
  ///  P8.1 is used as alternate output for the  CCU60 output(CC61)
  ///  - push/pull output is selected

  ///  P8.0 - P8.3 output driver characteristic: strong driver
  ///  P8.4 - P8.6 output driver characteristic: strong driver

  ///  P8.0 - P8.3 output edge characteristic: sharp edge mode
  ///  P8.4 - P8.6 output edge characteristic: sharp edge mode


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P9:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P9 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P10:
  ///  -----------------------------------------------------------------------
  ///  P10.0 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P10.1 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P10.2 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P10.3 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P10.4 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P10.5 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P10.6 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P10.7 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level

  ///  P10.0 - P10.3 output driver characteristic: strong driver
  ///  P10.4 - P10.7 output driver characteristic: strong driver
  ///  P10.8 - P10.11 output driver characteristic: strong driver
  ///  P10.12 - P10.15 output driver characteristic: strong driver

  ///  P10.0 - P10.3 output edge characteristic: sharp edge mode
  ///  P10.4 - P10.7 output edge characteristic: sharp edge mode
  ///  P10.8 - P10.11 output edge characteristic: sharp edge mode
  ///  P10.12 - P10.15 output edge characteristic: sharp edge mode

  P10_IOCR00     =  0x0080;      // load port control register 0
  P10_IOCR01     =  0x0080;      // load port control register 1
  P10_IOCR02     =  0x0080;      // load port control register 2
  P10_IOCR03     =  0x0080;      // load port control register 3
  P10_IOCR04     =  0x0080;      // load port control register 4
  P10_IOCR05     =  0x0080;      // load port control register 5
  P10_IOCR06     =  0x0080;      // load port control register 6
  P10_IOCR07     =  0x0080;      // load port control register 7

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P11:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P11 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P15:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P15 is used
  ///  - Port15 Data register P15(Read only)



  // USER CODE BEGIN (IO_Function,3)

  // USER CODE END

} //  End of function IO_vInit




// USER CODE BEGIN (IO_General,10)

// USER CODE END

