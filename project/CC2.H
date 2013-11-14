//****************************************************************************
// @Module        Capture / Compare Unit 2 (CAPCOM2)
// @Filename      CC2.H
// @Project       balancebot.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE167F-96F66
//
// @Compiler      Keil
//
// @Codegenerator 2.2
//
// @Description   This file contains all function prototypes and macros for 
//                the CC2 module.
//
//----------------------------------------------------------------------------
// @Date          14.11.2013 13:45:21
//
//****************************************************************************

// USER CODE BEGIN (CC2_Header,1)

// USER CODE END



#ifndef _CC2_H_
#define _CC2_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (CC2_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (CC2_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

//   This parameter identifies CAPCOM2 timer 7
#define CC2_TIMER_7 7

//   This parameter identifies CAPCOM2 timer 8
#define CC2_TIMER_8 8

//   This parameter identifies CAPCOM2 channel 16
#define CC2_CC_16 16

//   This parameter identifies CAPCOM2 channel 17
#define CC2_CC_17 17


// USER CODE BEGIN (CC2_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (CC2_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (CC2_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (CC2_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void CC2_vInit(void);


// USER CODE BEGIN (CC2_Header,8)

// USER CODE END


//****************************************************************************
// @Macro         CC2_vStartTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro starts the selected CAPCOM2 timer. The timer 
//                continues counting from where it stopped. 
//                
//                The following definitions for TimerNr are available: 
//                CC2_TIMER_7
//                CC2_TIMER_8
//                (see @Defines in header file)
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CAPCOM2 timer to be started
//
//----------------------------------------------------------------------------
// @Date          14.11.2013
//
//****************************************************************************

#define CC2_vStartTmr(TimerNr) CC2_vStartTmr_##TimerNr()
#define CC2_vStartTmr_CC2_TIMER_7() CC2_T78CON_T7R = 1
#define CC2_vStartTmr_CC2_TIMER_8() CC2_T78CON_T8R = 1


//****************************************************************************
// @Macro         CC2_vStopTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro stops the selected CAPCOM2 timer. The content of 
//                the timer register remains unchanged. 
//                
//                The following definitions for TimerNr are available: 
//                CC2_TIMER_7
//                CC2_TIMER_8
//                (see @Defines in header file)
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CAPCOM2 timer to be stopped
//
//----------------------------------------------------------------------------
// @Date          14.11.2013
//
//****************************************************************************

#define CC2_vStopTmr(TimerNr) CC2_vStopTmr_##TimerNr()
#define CC2_vStopTmr_CC2_TIMER_7() CC2_T78CON_T7R = 0
#define CC2_vStopTmr_CC2_TIMER_8() CC2_T78CON_T8R = 0


//****************************************************************************
// @Macro         CC2_vSetCCxReg(RegName, Value) 
//
//----------------------------------------------------------------------------
// @Description   This macro loads the selected CAPCOM2 register with the 
//                parameter Value. 
//                
//                The following definitions are available for RegName (only 
//                for enabled CAPCOM2 channels): 
//                CC2_CC_16 .. CC2_CC_31
//                (see @Defines in header file)
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    RegName: 
//                Name of the CAPCOM2 channel to be loaded
// @Parameters    Value: 
//                16-bit Value with which the CAPCOM2 register is to be loaded
//
//----------------------------------------------------------------------------
// @Date          14.11.2013
//
//****************************************************************************

#define CC2_vSetCCxReg(RegName, Value) CC2_vSetCCxReg_##RegName(Value)
#define CC2_vSetCCxReg_CC2_CC_16(Value) CC2_CC16 = Value
#define CC2_vSetCCxReg_CC2_CC_17(Value) CC2_CC17 = Value
#define CC2_vSetCCxReg_CC2_CC_18(Value) CC2_CC18 = Value
#define CC2_vSetCCxReg_CC2_CC_19(Value) CC2_CC19 = Value
#define CC2_vSetCCxReg_CC2_CC_20(Value) CC2_CC20 = Value
#define CC2_vSetCCxReg_CC2_CC_21(Value) CC2_CC21 = Value
#define CC2_vSetCCxReg_CC2_CC_22(Value) CC2_CC22 = Value
#define CC2_vSetCCxReg_CC2_CC_23(Value) CC2_CC23 = Value
#define CC2_vSetCCxReg_CC2_CC_24(Value) CC2_CC24 = Value
#define CC2_vSetCCxReg_CC2_CC_25(Value) CC2_CC25 = Value
#define CC2_vSetCCxReg_CC2_CC_26(Value) CC2_CC26 = Value
#define CC2_vSetCCxReg_CC2_CC_27(Value) CC2_CC27 = Value
#define CC2_vSetCCxReg_CC2_CC_28(Value) CC2_CC28 = Value
#define CC2_vSetCCxReg_CC2_CC_29(Value) CC2_CC29 = Value
#define CC2_vSetCCxReg_CC2_CC_30(Value) CC2_CC30 = Value
#define CC2_vSetCCxReg_CC2_CC_31(Value) CC2_CC31 = Value


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************



// USER CODE BEGIN (CC2_Header,8)

// USER CODE END


#endif  // ifndef _CC2_H_
