#include "SysTick.h"

// Initialize SysTick with busy wait running at bus clock.
void SysTick_Init(void){
  NVIC_ST_CTRL_R = 0;                   // disable SysTick during setup
  NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;  // maximum reload value
  NVIC_ST_CURRENT_R = 0;                // any write to current clears it
                                        // enable SysTick with core clock
  NVIC_ST_CTRL_R =5;
}

// Time delay using busy wait.
// The delay parameter is in units of the core clock. (units of 20 nsec for 50 MHz clock)
void SysTick_delay(uint32 delay){
  volatile uint32 elapsedTime;
  uint32 startTime = NVIC_ST_CURRENT_R;
  do{
    elapsedTime = (startTime-NVIC_ST_CURRENT_R)&0x00FFFFFF;
  }
  while(elapsedTime <= delay);
}

// Time delay using busy wait.
void SysTick_delay_ms(uint32 delay_in_ms){
  uint32 counts=(0.001*delay_in_ms*FREQUENCY);
	if(counts<=(0xFFFFFF-1)){
    SysTick_delay(counts-1); 		
	}
	else {
		int i;
	for(i=0;i<(int)(counts/0xFFFFFF);i++){
		SysTick_delay(16000000-1);
	}
	SysTick_delay((((double)counts/0xFFFFFF)-((int)(counts/0xFFFFFF)))*16000000-1);
	}
}
