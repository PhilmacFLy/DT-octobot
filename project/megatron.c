
#include "XE16xREGS.H"

#include "GPT1.H"
#include "IO.H"
#include "megatron.h"

#define ROLLOUTMEGATRONCODE(timeridx)   signed int value; \
										GPT1_vStop_Tmr(timeridx); \
										value = (signed int) GPT1_uwReadTmr(timeridx); \
										GPT1_vLoadTmr(timeridx, 0);	\
										GPT1_vStartTmr(timeridx); \
										if (value < 0) return (unsigned int) (-value); \
										else return (unsigned int) (value)

			
unsigned int ReadMegatronLeft()
{
  //ROLLOUTMEGATRONCODE(GPT1_TIMER_3);
  signed int value; 
  GPT1_vStopTmr(GPT1_TIMER_3);
  value = (signed int) GPT1_uwReadTmr(GPT1_TIMER_3);
  GPT1_vLoadTmr(GPT1_TIMER_3, 0);
  GPT1_vStartTmr(GPT1_TIMER_3);
  if (value < 0) return (unsigned int) (-value);
  else return (unsigned int) (value);
}

unsigned int ReadMegatronRight()
{
  signed int value; 
  GPT1_vStopTmr(GPT1_TIMER_4);
  value = (signed int) GPT1_uwReadTmr(GPT1_TIMER_4);
  GPT1_vLoadTmr(GPT1_TIMER_4, 0);
  GPT1_vStartTmr(GPT1_TIMER_4);
  if (value < 0) return (unsigned int) (-value);
  else return (unsigned int) (value);
}
