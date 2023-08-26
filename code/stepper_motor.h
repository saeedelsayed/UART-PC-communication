/**************************************************************************************************************
 *
 * MODULE: STEPPER MOTOR
 *
 * FILE NAME: stepper_motor.h
 *
 * Description: Header file for the STEPPER MOTOR driver
 *
 * Created on: August 25, 2023
 *
 * Author: Saeed Elsayed
 *
 **************************************************************************************************************/

#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

#include "std_types.h"
#include "gpio.h"


#define HALF_WAVE_STEPS  8   // decide if we move by half angle wave or full angle wave

// define the numbers which correspond to each angle
#define WAVE_STEP_45   8
#define WAVE_STEP_90   12
#define WAVE_STEP_135  4
#define WAVE_STEP_180  6
#define WAVE_STEP_225  2
#define WAVE_STEP_270  3
#define WAVE_STEP_315  1
#define WAVE_STEP_360  9

#define STEPPER_MOTOR_PORT_ID               PORTD_ID    // choose the port of the stepper motor

#define STEPPER_MOTOR_FIRST_INPUT_PIN_ID    PIN4_ID     // choose the pin of input1


// enumeration to decide the state required for the motor
typedef enum
{
	STEPPER_STOP, STEPPER_CLOCK_WISE, STEPPER_ANTI_CLOCK_WISE
}stepperMotor_direction;

/*
 * Description:
 * function that initialize the stepper motor
 */
void stepperMotor_Init();

/*
 * Description:
 * function which determine the direction of rotation and steps
 */
void stepperMotor_rotate(stepperMotor_direction direction, uint8 step);



#endif /* STEPPER_MOTOR_H_ */
