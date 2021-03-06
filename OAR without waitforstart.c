#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     irSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     DumpMotorLeft, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     DumpMotorRight, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     SpinnyThing,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     LeftDrive,     tmotorTetrix, openLoop, reversed, driveLeft)
#pragma config(Motor,  mtr_S1_C3_2,     RightDrive,    tmotorTetrix, openLoop, driveRight)
#pragma config(Servo,  srvo_S1_C4_1,    SideHook,             tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    BackHook,             tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

  return;
}

task main()
{
  initializeRobot();

  while (true)
  {
  	motor[LeftDrive]=75;
  	motor[RightDrive]=75;
  	wait1Msec(2000);
  	motor[LeftDrive]=65;
  	wait1Msec(500);
  	motor[LeftDrive]=75;
  	motor[RightDrive]=-75;
  	wait1Msec(1000);
  	servo [SideHook] = 90;
  }
}
