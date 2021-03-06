#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S4,     irSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     DumpMotorLeft, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     DumpMotorRight, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     SpinnyThing,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     LeftDrive,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     RightDrive,    tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    SideHook,             tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    BackHook,             tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

void initializeRobot()
{
	// Place code here to sinitialize servos to starting positions.
	// Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

	return;
}

#include "hitechnic-irseeker-v2.h"

task main()
{
	tHTIRS2 irSeeker;
	initSensor(&irSeeker, S4);

	// Create struct to hold sensor data


	initializeRobot();

	// Wait for the beginning of autonomous phase.

	readSensor(&irSeeker);
	if(irSeeker.enhStrength < 20)
	{
		motor[LeftDrive]=75;
		motor[RightDrive]=75;
		wait10Msec(1300);
		motor[LeftDrive]=0;
		wait10Msec(500);
		motor[LeftDrive]=75;
		wait10Msec(500);
		motor[LeftDrive]=0;
		motor[RightDrive]=0;
	}
	if(irSeeker.enhStrength > 20)
	{
		if(irSeeker.enhStrength < 80)
		{
			motor[LeftDrive]=65;
			motor[RightDrive]=75;
			wait10Msec(500);
			motor[LeftDrive]=75;
			wait10Msec(500);
			motor[RightDrive]=0;
			wait10Msec(500);
			motor[RightDrive]=75;
			wait10Msec(700);
			motor[LeftDrive]=0;
			motor[RightDrive]=0;
		}
	}
	if(irSeeker.enhStrength > 80)
	{
		motor[LeftDrive]=75;
		motor[RightDrive]=75;
		wait10Msec(1800);
		motor[LeftDrive]=0;
		motor[RightDrive]=0;
	}



	while (true)
	{}
}
