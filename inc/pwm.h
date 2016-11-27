/* 
 * File:   pwm.h
 * Author: Miroslav Bozic
 *
 * Created on November 26, 2016, 7:19 AM
 */

#ifndef PWM_H
#define	PWM_H

#define P1A     PIN_C5
#define P1B     PIN_C4

/* Peripheral interrupt register */
#byte PIR1=0x0c
#bit TMR2IF=PIR1.1
/* Timer 2 control register */
#byte T2CON=0x12
#bit TMR2ON=T2CON.2
/* Timer 2 register */
#byte TMR2=0x11

/*Function prototypes*/
void pwm_set_deadband(int8 deadband);
void pwm_init(void);
void pwm_start(void);
void pwm_stop(void);
void pwm_high_z(void);

#endif	/* PWM_H */

