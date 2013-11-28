//****************************************************************************
// @Module        Capture / Compare Unit 60 (CCU60)
// @Filename      CCU60.H
// @Project       balancebot.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE167F-96F66
//
// @Compiler      Keil
//
// @Codegenerator 2.2
//
// @Description   This file contains all function prototypes and macros for 
//                the CCU60 module.
//
//----------------------------------------------------------------------------
// @Date          28.11.2013 13:40:52
//
//****************************************************************************

// USER CODE BEGIN (CCU60_Header,1)

// USER CODE END



#ifndef _CCU60_H_
#define _CCU60_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (CCU60_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (CCU60_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

//   This parameter identifies CCU60 timer 12
#define CCU60_TIMER_12 12

//   This parameter identifies CCU60 timer 13
#define CCU60_TIMER_13 13

//   This parameter identifies CCU60 channel 0
#define CCU60_CHANNEL_0 0

//   This parameter identifies CCU60 channel 1
#define CCU60_CHANNEL_1 1

//   This parameter identifies CCU60 channel 2
#define CCU60_CHANNEL_2 2

//   This parameter identifies CCU60 channel 3
#define CCU60_CHANNEL_3 3


// USER CODE BEGIN (CCU60_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (CCU60_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (CCU60_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (CCU60_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void CCU60_vInit(void);


// USER CODE BEGIN (CCU60_Header,8)

// USER CODE END


//****************************************************************************
// @Macro         CCU60_vStartTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro starts the selected CCU60 timer. The timer 
//                continues counting from where it stopped. 
//                
//                The following definitions for TimerNr are available: 
//                CCU60_TIMER_12
//                CCU60_TIMER_13
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CCU60 timer to be started
//
//----------------------------------------------------------------------------
// @Date          28.11.2013
//
//****************************************************************************

#define CCU60_vStartTmr(TimerNr) CCU60_vStartTmr_##TimerNr()
#define CCU60_vStartTmr_CCU60_TIMER_12() CCU60_TCTR4 |= 0x0002
#define CCU60_vStartTmr_CCU60_TIMER_13() CCU60_TCTR4 |= 0x0200


//****************************************************************************
// @Macro         CCU60_vStopTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro stops the selected CCU60 timer. The content of 
//                the timer register remains unchanged. 
//                
//                The following definitions for TimerNr are available: 
//                CCU60_TIMER_12
//                CCU60_TIMER_13
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CCU60 timer to be stopped
//
//----------------------------------------------------------------------------
// @Date          28.11.2013
//
//****************************************************************************

#define CCU60_vStopTmr(TimerNr) CCU60_vStopTmr_##TimerNr()
#define CCU60_vStopTmr_CCU60_TIMER_12() CCU60_TCTR4 |= 0x0001
#define CCU60_vStopTmr_CCU60_TIMER_13() CCU60_TCTR4 |= 0x0100


//****************************************************************************
// @Macro         CCU60_vEnableShadowTransfer(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro enables the transfer from the shadow registers 
//                to the actual CCU60 registers.
//                
//                The following definitions for TimerNr are available: 
//                CCU60_TIMER_12
//                CCU60_TIMER_13
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CCU60 timer to be used
//
//----------------------------------------------------------------------------
// @Date          28.11.2013
//
//****************************************************************************

#define CCU60_vEnableShadowTransfer(TimerNr) CCU60_vEnableShadowTransfer_##TimerNr()
#define CCU60_vEnableShadowTransfer_CCU60_TIMER_12() CCU60_TCTR4 |= 0x0040
#define CCU60_vEnableShadowTransfer_CCU60_TIMER_13() CCU60_TCTR4 |= 0x4000


//****************************************************************************
// @Macro         CCU60_vLoadChannelShadowRegister(ChName, Value) 
//
//----------------------------------------------------------------------------
// @Description   This macro loads the selected CCU60 channel shadow register 
//                with the parameter Value. 
//                
//                The following definitions are available for RegName: 
//                CCU60_CHANNEL_0 .. CCU60_CHANNEL_3 (see @Defines in header 
//                file)
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    ChName: 
//                Name of the CCU60 channel to be loaded
// @Parameters    Value: 
//                16-bit Value with which the CCU60 shadow register is to be 
//                loaded
//
//----------------------------------------------------------------------------
// @Date          28.11.2013
//
//****************************************************************************

#define CCU60_vLoadChannelShadowRegister(ChName, Value) CCU60_vLoadChannelShadowRegister_##ChName(Value)
#define CCU60_vLoadChannelShadowRegister_CCU60_CHANNEL_0(Value) CCU60_CC60SR = Value
#define CCU60_vLoadChannelShadowRegister_CCU60_CHANNEL_1(Value) CCU60_CC61SR = Value
#define CCU60_vLoadChannelShadowRegister_CCU60_CHANNEL_2(Value) CCU60_CC62SR = Value
#define CCU60_vLoadChannelShadowRegister_CCU60_CHANNEL_3(Value) CCU60_CC63SR = Value


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

#define CCU60_NodeI0_INT    0x30


// USER CODE BEGIN (CCU60_Header,9)

// USER CODE END


#endif  // ifndef _CCU60_H_
