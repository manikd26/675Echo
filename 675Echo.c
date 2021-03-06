#pragma config(Sensor, in1,    liftPot,        sensorPotentiometer)
#pragma config(Motor,  port1,           leftTopLift,   tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           hangMotors,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftDrive,     tmotorVex393TurboSpeed_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           rightFront,    tmotorVex393TurboSpeed_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port5,           rightBack,     tmotorVex393TurboSpeed_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port6,           leftBotLift,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftMidLift,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           rightBotLift,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           rightMidLift,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightTopLift,  tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"

#include "drive.h"
//#include "liftPot.h"
#include "manualLift.h"
#include "auton.h"
//#include "fuckthislift.h"

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;
}




task autonomous()
{
	if(getTaskState(auton) == taskStateStopped)
	startTask(auton);
}




task usercontrol()
{
	while (true)
	{
		if(getTaskState(driveTask) == taskStateStopped)
			startTask(driveTask);
	//	if (getTaskState(moveLiftPot) == taskStateStopped)
	//	startTask(moveLiftPot);
			if (getTaskState(manualLift) == taskStateStopped)
			startTask(manualLift);
	if (getTaskState(hangTask) == taskStateStopped)
		startTask(hangTask);
	}
}
