
#include "XE16xREGS.H"

#include "GPT2.H"
#include "IO.H"
#include "megatron.h"
			
unsigned int ReadMegatronLeft()
{
  unsigned int value; 
  GPT2_vStopTmr(GPT2_TIMER_5);
  value = GPT2_uwReadTmr(GPT2_TIMER_5);
  GPT2_vLoadTmr(GPT2_TIMER_5, 0);
  GPT2_vStartTmr(GPT2_TIMER_5);
  return value;
}

unsigned int ReadMegatronRight()
{
  unsigned int value; 
  GPT2_vStopTmr(GPT2_TIMER_6);
  value = GPT2_uwReadTmr(GPT2_TIMER_6);
  GPT2_vLoadTmr(GPT2_TIMER_6, 0);
  GPT2_vStartTmr(GPT2_TIMER_6);
  return value;
}
