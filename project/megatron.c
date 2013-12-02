
#include "XE16xREGS.H"

#include "GPT1.H"
#include "IO.H"
#include "megatron.h"
			
unsigned int ReadMegatronLeft()
{
  //ROLLOUTMEGATRONCODE(GPT1_TIMER_3);
  unsigned int value; 
  GPT1_vStopTmr(GPT1_TIMER_3);
  value = (signed int) GPT1_uwReadTmr(GPT1_TIMER_3);
  GPT1_vLoadTmr(GPT1_TIMER_3, 0);
  GPT1_vStartTmr(GPT1_TIMER_3);
  return value;
}

unsigned int ReadMegatronRight()
{
  unsigned int value; 
  GPT1_vStopTmr(GPT1_TIMER_4);
  value = (signed int) GPT1_uwReadTmr(GPT1_TIMER_4);
  GPT1_vLoadTmr(GPT1_TIMER_4, 0);
  GPT1_vStartTmr(GPT1_TIMER_4);
  return value;
}
