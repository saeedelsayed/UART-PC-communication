/**************************************************************************************************************
 *
 * MODULE: STEPPER MOTOR
 *
 * FILE NAME: stepper_motor.c
 *
 * Description: Source file for the STEPPER MOTOR driver
 *
 * Created on: August 25, 2023
 *
 * Author: Saeed Elsayed
 *
 **************************************************************************************************************/

#include "stepper_motor.h"
#include <avr/io.h>

// array to carry all the angles of the stepper motor
uint8 motor_steps[HALF_WAVE_STEPS] = {WAVE_STEP_45,WAVE_STEP_90,WAVE_STEP_135,WAVE_STEP_180,
		WAVE_STEP_225,WAVE_STEP_270,WAVE_STEP_315,WAVE_STEP_360};


void stepperMotor_Init()
{
    // make all pins of the stepper motor output pins
	GPIO_setupPinDirection(STEPPER_MOTOR_PORT_ID, STEPPER_MOTOR_FIRST_INPUT_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(STEPPER_MOTOR_PORT_ID, STEPPER_MOTOR_FIRST_INPUT_PIN_ID+1, PIN_OUTPUT);
	GPIO_setupPinDirection(STEPPER_MOTOR_PORT_ID, STEPPER_MOTOR_FIRST_INPUT_PIN_ID+2, PIN_OUTPUT);
	GPIO_setupPinDirection(STEPPER_MOTOR_PORT_ID, STEPPER_MOTOR_FIRST_INPUT_PIN_ID+3, PIN_OUTPUT);
    // then initially make their values equal to zero
	GPIO_writePin(STEPPER_MOTOR_PORT_ID, STEPPER_MOTOR_FIRST_INPUT_PIN_ID, LOGIC_LOW);
	GPIO_writePin(STEPPER_MOTOR_PORT_ID, STEPPER_MOTOR_FIRST_INPUT_PIN_ID+1, LOGIC_LOW);
	GPIO_writePin(STEPPER_MOTOR_PORT_ID, STEPPER_MOTOR_FIRST_INPUT_PIN_ID+2, LOGIC_LOW);
	GPIO_writePin(STEPPER_MOTOR_PORT_ID, STEPPER_MOTOR_FIRST_INPUT_PIN_ID+3, LOGIC_LOW);

}

void stepperMotor_rotate(stepperMotor_direction direction, uint8 steps)
{
	switch(STEPPER_MOTOR_PORT_ID)  // check the port of the motor then clear the 4 pins of the motor to write them again
	{
	case PORTA_ID:
		PORTA &= ~(0xF << STEPPER_MOTOR_FIRST_INPUT_PIN_ID);   // clear the 4 pins depending on the first pin of them
		if(direction == STEPPER_CLOCK_WISE)    // if the direction clock wise then iterate over the array from left to right
		{
			uint8 indx = 0;
			for(uint8 i = 0; i < steps; i++)
			{
				PORTA |= (motor_steps[indx] << STEPPER_MOTOR_FIRST_INPUT_PIN_ID);  // make the 4 pins in the port equal to value in the array
				indx++;
				if(indx == 8)      // if steps are more than 8 then we should clear indx to re-iterate over the array again
					indx = 0;
			}
		}
		else {    // if direction is anti clock wise then we should iterate from right to left
			sint8 indx = 6;
			for(uint8 i = 0; i < steps; i++)
			{
				PORTA |= (motor_steps[indx] << STEPPER_MOTOR_FIRST_INPUT_PIN_ID);
				indx--;
				if(indx == -1)  // check if index reached -1 to make it equal 6 again
					indx = 6;
			}
		}
		break;
	case PORTB_ID:
		PORTB &= ~(0xF << STEPPER_MOTOR_FIRST_INPUT_PIN_ID);
		if(direction == STEPPER_CLOCK_WISE)
		{
			uint8 indx = 0;
			for(uint8 i = 0; i < steps; i++)
			{
				PORTB |= (motor_steps[indx] << STEPPER_MOTOR_FIRST_INPUT_PIN_ID);
				indx++;
				if(indx == 8)
					indx = 0;
			}
		}
		else {
			sint8 indx = 6;
			for(uint8 i = 0; i < steps; i++)
			{
				PORTB |= (motor_steps[indx] << STEPPER_MOTOR_FIRST_INPUT_PIN_ID);
				indx--;
				if(indx == -1)
					indx = 6;
			}
		}
		break;
	case PORTC_ID:
		PORTC &= ~(0xF << STEPPER_MOTOR_FIRST_INPUT_PIN_ID);
		if(direction == STEPPER_CLOCK_WISE)
		{
			uint8 indx = 0;
			for(uint8 i = 0; i < steps; i++)
			{
				PORTC |= (motor_steps[indx] << STEPPER_MOTOR_FIRST_INPUT_PIN_ID);
				indx++;
				if(indx == 8)
					indx = 0;
			}
		}
		else {
			sint8 indx = 6;
			for(uint8 i = 0; i < steps; i++)
			{
				PORTC |= (motor_steps[indx] << STEPPER_MOTOR_FIRST_INPUT_PIN_ID);
				indx--;
				if(indx == -1)
					indx = 6;
			}
		}
		break;
	case PORTD_ID:
		PORTD &= ~(0xF << STEPPER_MOTOR_FIRST_INPUT_PIN_ID);
		if(direction == STEPPER_CLOCK_WISE)
		{
			uint8 indx = 0;
			for(uint8 i = 0; i < steps; i++)
			{
				PORTD |= (motor_steps[indx] << STEPPER_MOTOR_FIRST_INPUT_PIN_ID);
				indx++;
				if(indx == 8)
					indx = 0;
			}
		}
		else {
			sint8 indx = 6;
			for(uint8 i = 0; i < steps; i++)
			{
				PORTD |= (motor_steps[indx] << STEPPER_MOTOR_FIRST_INPUT_PIN_ID);
				indx--;
				if(indx == -1)
					indx = 6;
			}
		}
		break;

	}

}

