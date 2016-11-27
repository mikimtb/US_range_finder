#include "inc/transceiver.h"
#include "inc/pwm.h"

/**
 * Function produce pulse_no pulses on PWM output pins
 * @param pulse_no - Number of pulses that will be produced
 */
void transceiver_transmit(int8 pulse_no)
{
    pwm_start();
    /* Transmit pulse_no pulses */
    TMR2IF = 0;
    while (pulse_no > 0)
    {
        if(TMR2IF)
        {
            pulse_no--;
            TMR2IF = 0; 
        }
    }
    pwm_stop();
    delay_us(500);
    //pwm_high_z();
}
/**
 * Function switch transceiver in listen mode
 * @return TRUE if echo is detected, FALSE if echo is not detected in Nms
 */
short transceiver_listen()
{
    /* Switch P1A - RC5 to high Z mode */
    set_tris_c(get_tris_c() | 0b00100000);
    /* Switch P1B - RC4 to logic zero */
    output_low(P1B);
    
    /**
     * Add listener code here
     */
    
    return 0;
}


