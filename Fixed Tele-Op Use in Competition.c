#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     DumpMotorLeft, tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     DumpMotorRight, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     SpinnyThing,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     LeftDrive,     tmotorTetrix, openLoop, driveLeft)
#pragma config(Motor,  mtr_S1_C3_2,     RightDrive,    tmotorTetrix, openLoop, driveRight)
#pragma config(Servo,  srvo_S1_C4_1,    BackHook,             tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    SideHook,             tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Tele-Operation Mode Code Template
//
// This file contains a template for simplified creation of an tele-op program for an FTC
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

typedef enum{
	btnX = 1,
	btnA = 2,
	btnB = 3,
	btnY = 4,
	btnLB = 5,
	btnRB = 6,
	btnLT = 7,
	btnRT = 8
}Buttons;



void initializeRobot()
{
	// Place code here to sinitialize servos to starting positions.
	// Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

	return;
}



task main()
{
	bool Sweeper=false;
	bool Tilter=false;
	initializeRobot();

	waitForStart(); // Wait for the beginning of autonomous phase.

	while (true)
	{
		getJoystickSettings(joystick);

		if ( joystick.joy1_y2 < -10 || joystick.joy1_y2 > 10 )//set deadzone for joystick 1 user 1
		{
			motor[LeftDrive] = joystick.joy1_y2 * -75.0/127.0;
		}
		else{
			motor[LeftDrive] = 0;
		}
		if ( joystick.joy1_y1 < -10 || joystick.joy1_y1 > 10 )//set deadzone for joystick 2 user 1
		{
			motor[RightDrive] = joystick.joy1_y1 * 75.0/127.0;
		}
		else{
			motor[RightDrive] = 0;
		}
		if (joy1Btn(5)==true) //if Button LB is tapped then sweeper turns on
		{
			Sweeper=true;
		}
		if (joy1Btn(6)==true) //if Button RB is tapped then sweeper turns off
		{
			Sweeper=false;
		}
		if ( Sweeper==true) //if sweeper is true then it turns on
		{
			motor[SpinnyThing] = 100;
		}
		else //if sweeper is not true then it turns off
		{
			motor[SpinnyThing] = 0;
		}

		//Zach's comments
		if ( joystick.joy2_y1 < -10 || joystick.joy2_y1 > 10 )//set deadzone for joystick 1 user 2
		{
			motor[DumpMotorLeft] = joystick.joy2_y1 * -35.0/127.0;
		}
		else{
			motor[DumpMotorLeft] = 0;
		}
		if ( joystick.joy2_y2 < -10 || joystick.joy2_y2 > 10 )//set deadzone for joystick 2 user 2
		{
			motor[DumpMotorRight] = joystick.joy2_y2 * -35.0/127.0;
		}
		else{
			motor[DumpMotorRight] = 0;
		}
		if (joy2Btn (5)==true)
		{
			servo [SideHook] = 0;			// This will put the "hook" down onto the ball holder, keeping it by us.
		}
		if (joy2Btn (6)==true)
		{
			servo [SideHook] = 180;			// This will lift the "hook", releasing the ball holder.
		}
		if (joy2Btn (7)==true)
		{
			servo [BackHook] = 0;
		}
		if (joy2Btn (8)==true)
		{
			servo [BackHook] = 20;
		}
	}
}
