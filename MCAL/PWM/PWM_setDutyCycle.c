

//----------------------- PWM_SetDuty --------------------------
// Set the duty cycle of an enabled PWM module/channel
// Inputs:  module - the PWM module name.
//          channel - the PWM channel name.
//          duty - the duty cycle as percentage.
// Outputs:  none.
void PWM_SetDuty(PWMModule module, PWMChannel channel, uint16 duty)
{
	switch(module) {
		uint16 period;
		case PWMModule0:
			
			switch (channel) {
				case PWM0 :
					period = PWM0_0_LOAD_R;
					PWM0_0_CMPA_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
					break;
				case PWM1 :
					period = PWM0_0_LOAD_R;
					PWM0_0_CMPB_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
					break;
				case PWM2 :
					period = PWM0_1_LOAD_R;
					PWM0_1_CMPA_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
					
					break;
				case PWM3 :
					period = PWM0_1_LOAD_R;
					PWM0_1_CMPB_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
					
					break;
				case PWM4 :
					period = PWM0_2_LOAD_R;
					PWM0_2_CMPA_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					break;
				case PWM5 :
					period = PWM0_2_LOAD_R;
					PWM0_2_CMPB_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					break;
				case PWM6 :
					period = PWM0_3_LOAD_R;
					PWM0_3_CMPA_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
					
					break;
				case PWM7 :
					period = PWM0_3_LOAD_R;
					PWM0_3_CMPB_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
					
					break;
				
				default:
					break;
				
			};
			break;
			
			case PWMModule1:
				switch (channel) {
				case PWM0 :
					period = PWM1_0_LOAD_R;
					PWM1_0_CMPA_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
					
					break;
				case PWM1 :
					period = PWM1_0_LOAD_R;
					PWM1_0_CMPB_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					break;
				case PWM2 :
					period = PWM1_1_LOAD_R;
					PWM1_1_CMPA_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					break;
				case PWM3 :
					period = PWM1_1_LOAD_R;
					PWM1_1_CMPB_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					break;
				case PWM4 :
					period = PWM1_2_LOAD_R;
					PWM1_2_CMPA_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					break;
				case PWM5 :
					period = PWM1_2_LOAD_R;
					PWM1_2_CMPB_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					break;
				case PWM6 :
					period = PWM1_3_LOAD_R;
					PWM1_3_CMPA_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					break;
				
				case PWM7 :
					period = PWM1_3_LOAD_R;
					PWM1_3_CMPB_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					break;
				
				default:
					break;
				
			};
			break;
	};
}