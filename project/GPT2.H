//****************************************************************************
// @Module        General Purpose Timer Unit (GPT2)
// @Filename      GPT2.H
// @Project       balancebot.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE167F-96F66
//
// @Compiler      Keil
//
// @Codegenerator 2.2
//
// @Description   This file contains all function prototypes and macros for 
//                the GPT2 module.
//
//----------------------------------------------------------------------------
// @Date          21.11.2013 14:26:55
//
//****************************************************************************

// USER CODE BEGIN (GPT2_Header,1)

// USER CODE END



#ifndef _GPT2_H_
#define _GPT2_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (GPT2_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (GPT2_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

//   This parameter identifies GPT2 timer 5
#define GPT2_TIMER_5 5

//   This parameter identifies GPT2 timer 6
#define GPT2_TIMER_6 6

// USER CODE BEGIN (GPT2_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (GPT2_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (GPT2_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (GPT2_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void GPT2_vInit(void);

// USER CODE BEGIN (GPT2_Header,8)

// USER CODE END

//****************************************************************************
// @Macro         GPT2_vStartTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro starts the selected GPT2 timer. The timer 
//                continues to count from where it had stopped. The following 
//                definitions are available for TimerNr:
//                GPT2_TIMER_5
//                GPT2_TIMER_6
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                The name of the timer to be started
//
//----------------------------------------------------------------------------
// @Date          21.11.2013
//
//****************************************************************************

#define GPT2_vStartTmr(TimerNr) GPT2_vStartTmr_##TimerNr()
#define GPT2_vStartTmr_GPT2_TIMER_5() GPT12E_T5CON_T5R = 1
#define GPT2_vStartTmr_GPT2_TIMER_6() GPT12E_T6CON_T6R = 1


//****************************************************************************
// @Macro         GPT2_vStopTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro stops the selected GPT2 timer. The contents of 
//                the timer register remain unchanged. The remote control of 
//                the selected timer is cleared. The following definitions 
//                are available for TimerNr:
//                GPT2_TIMER_5
//                GPT2_TIMER_6
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                The name of the timer to be stopped
//
//----------------------------------------------------------------------------
// @Date          21.11.2013
//
//****************************************************************************

#define GPT2_vStopTmr(TimerNr) GPT2_vStopTmr_##TimerNr()
#define GPT2_vStopTmr_GPT2_TIMER_5() GPT12E_T5CON_T5R = 0; GPT12E_T5CON_T5RC = 0
#define GPT2_vStopTmr_GPT2_TIMER_6() GPT12E_T6CON_T6R = 0


//****************************************************************************
// @Macro         GPT2_uwReadTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the contents of the selected GPT2 timer. 
//                The timer is not stopped. Access of the CPU to the 
//                registers of the timer is of higher priority than a timer 
//                increment, a reload or a capture event. The following 
//                definitions are available for TimerNr:
//                GPT2_TIMER_5
//                GPT2_TIMER_6
//
//----------------------------------------------------------------------------
// @Returnvalue   Current 16-bit value of the timer
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                The name of the timer to be readed
//
//----------------------------------------------------------------------------
// @Date          21.11.2013
//
//****************************************************************************

#define GPT2_uwReadTmr(TimerNr) GPT2_uwReadTmr_##TimerNr()
#define GPT2_uwReadTmr_GPT2_TIMER_5() GPT12E_T5
#define GPT2_uwReadTmr_GPT2_TIMER_6() GPT12E_T6


//****************************************************************************
// @Macro         GPT2_vLoadTmr(TimerNr, Value) 
//
//----------------------------------------------------------------------------
// @Description   This macro loads the selected GPT2 timer with the forwarded 
//                value. The timer is not stopped. The access of the CPU to 
//                the registers of the timers is of higher priority than a 
//                timer increment, a reload or a capture event. The following 
//                definitions are available for TimerNr:
//                GPT2_TIMER_5
//                GPT2_TIMER_6
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                The name of the timer to be loaded
// @Parameters    Value: 
//                16-bit value to be loaded
//
//----------------------------------------------------------------------------
// @Date          21.11.2013
//
//****************************************************************************

#define GPT2_vLoadTmr(TimerNr, Value) GPT2_vLoadTmr_##TimerNr(Value)
#define GPT2_vLoadTmr_GPT2_TIMER_5(Value) GPT12E_T5 = Value
#define GPT2_vLoadTmr_GPT2_TIMER_6(Value) GPT12E_T6 = Value


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************


// USER CODE BEGIN (GPT2_Header,9)

// USER CODE END


#endif  // ifndef _GPT2_H_
