#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    Gyro,           sensorGyro)
#pragma config(Sensor, in2,    liftPot,        sensorPotentiometer)
#pragma config(Sensor, dgtl1,  pistonLaunch,   sensorDigitalOut)
#pragma config(Sensor, dgtl2,  pistonClaw,     sensorDigitalOut)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           rightClaw,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightMidLift,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightTopLift,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftMidLift,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftTopLift,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           rightFront,    tmotorVex393TurboSpeed_MC29, openLoop, reversed, driveRight, encoderPort, I2C_2)
#pragma config(Motor,  port7,           leftFront,     tmotorVex393TurboSpeed_MC29, openLoop, driveLeft, encoderPort, I2C_1)
#pragma config(Motor,  port8,           leftBack,      tmotorVex393TurboSpeed_MC29, openLoop, driveLeft)
#pragma config(Motor,  port9,           rightBack,     tmotorVex393TurboSpeed_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port10,          leftClaw,      tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)

#pragma competitionControl(Competition)

#include "Vex_Competition_Includes.c"

#include "drive.h"
#include "manualLift.h"
#include "auton.h"

//////////////////////////////////////////////////

const short leftbutton= 1;
const short centerbutton= 2;
const short rightbutton= 4;

int count = 0;

void waitforpress()
{
	while(nLCDButtons == 0){}
	wait1Msec (5);
}

void waitforrelease()
{
	while(nLCDButtons != 0){}
	wait1Msec (5);
}

//////////////////////////////////////////////////

void pre_auton()
{
	bStopTasksBetweenModes = true;

	nMotorEncoder(rightFront) = 0;
	nMotorEncoder(leftFront) = 0;
	SensorValue(Gyro) = 0;

	bLCDBacklight= true;

	clearLCDLine(0);
	clearLCDLine(1);

	//allows robot to restart from vexnet disconnect without reselecting autonomous code
	while( (nLCDButtons != kButtonCenter)  && bIfiRobotDisabled )
	{
		switch(count){
		case 0:
			displayLCDCenteredString(0, "No Autonomous");
			displayLCDCenteredString(1, "<		 Enter 		>");
			waitforpress();

			if (nLCDButtons == centerbutton)
			{
				waitforrelease();
				displayLCDCenteredString(0, "No Auton?");
				displayLCDCenteredString(1, "||YES||");
				wait1Msec (1000);
				waitforpress();
			}
			if(nLCDButtons == leftbutton)
			{
				waitforrelease();
				count = 3;
			}
			else if(nLCDButtons == rightbutton)
			{
				waitforrelease();
				count++;
			}
			break;

			/////////////////////////////////////////////////////////////////////////////////

		case 1:
			displayLCDCenteredString(0, "Blue Hang");
			displayLCDCenteredString(1, "<		 Enter 		>");
			waitforpress();

			if (nLCDButtons == centerbutton)
			{
				waitforrelease();
				displayLCDCenteredString(0, "Blue Hang?");
				displayLCDCenteredString(1, "||YES||");
				wait1Msec (1000);
				waitforpress();
			}
			if(nLCDButtons == leftbutton)
			{
				waitforrelease();
				count--;
			}
			else if(nLCDButtons == rightbutton)
			{
				waitforrelease();
				count++;
			}
			break;

			/////////////////////////////////////////////////////////////////////////////////

		case 2:
			displayLCDCenteredString(0, "Blue Near");
			displayLCDCenteredString(1, "<		 Enter 		>");
			waitforpress();

			if (nLCDButtons == centerbutton)
			{
				waitforrelease();
				displayLCDCenteredString(0, "Blue Near?");
				displayLCDCenteredString(1, "||YES||");
				wait1Msec (1000);
				waitforpress();
			}
			if(nLCDButtons == leftbutton)
			{
				waitforrelease();
				count--;
			}
			else if(nLCDButtons == rightbutton)
			{
				waitforrelease();
				count++;
			}
			break;

			/////////////////////////////////////////////////////////////////////////////////

		case 3:
			displayLCDCenteredString(0, "Fence");
			displayLCDCenteredString(1, "<		 Enter 		>");
			waitforpress();

			if (nLCDButtons == centerbutton)
			{
				waitforrelease();
				displayLCDCenteredString(0, "Fence?");
				displayLCDCenteredString(1, "||YES||");
				wait1Msec (1000);
				waitforpress();
			}
			if(nLCDButtons == leftbutton)
			{
				waitforrelease();
				count--;
			}
			else if(nLCDButtons == rightbutton)
			{
				waitforrelease();
				count = 0;
			}
			break;

			/////////////////////////////////////////////////////////////////////////////////

		default:
			displayLCDCenteredString(0, "No valid choice");
			displayLCDCenteredString(1, "was made!");
			break;

		}
	}
}

//////////////////////////////////////////////////

task autonomous()
{
	{
		bLCDBacklight= true;
		clearLCDLine(0);
		clearLCDLine(1);

		switch(count){

		case 0:
			displayLCDCenteredString(0, "No autonomous");
			displayLCDCenteredString(1, "is running!");
			wait1Msec(100);
			break;

			//////////////////////////////////////////////////////////////////////////////////////

		case 1:
			displayLCDCenteredString(0, "Blue Hang");
			displayLCDCenteredString(1, "is running!");
			wait1Msec(100);

			liftUp(450);
			wait(50);
			backward(127,25);
			wait(50);
			openClaw();
			wait(50);
			forward(127,500);
			wait(50);
			closeClaw();
			wait(50);
			liftUp(700);
			wait(50);
			backward(127, 150);
			wait(50);
			leftturn(127, 50);
			wait(50);
			forward(127, 650);
			wait(50);
			openClaw();

			break;

			///////////////////////////////////////////////////////////////////////////////////////

		case 2:
			displayLCDCenteredString(0, "Blue Near");
			displayLCDCenteredString(1, "is running!");
			wait1Msec(100);

			liftUp(450);
			wait(50);
			backward(127,25);
			wait(50);
			openClaw();
			wait(50);
			forward(127,500);
			wait(50);
			closeClaw();
			wait(50);
			liftUp(700);
			wait(50);
			backward(127, 150);
			wait(50);
			rightturn(127, 50);
			wait(50);
			forward(127, 650);
			wait(50);
			openClaw();


			break;
			/////////////////////////////////////////////////////////////////////////////////////////////

		case 3:
			displayLCDCenteredString(0, "Fence");
			displayLCDCenteredString(1, "is running!");
			wait1Msec(100);

			openClaw();
			wait(50);
			liftUp(1200);
			wait(50);
			rightturn(127, 15);
			wait(50);
			closeClaw();
			wait(5);
			forward(127, 1500);
			wait(50);
			leftturn(127,15);
			wait(50);
			backward(127, 200);
			break;

		}
	}
}

//////////////////////////////////////////////////

task usercontrol()
{
	while (true)
	{
		displayLCDCenteredString(0, "M + D");
		displayLCDCenteredString(1, "<3");

		if(getTaskState(driveTask) == taskStateStopped)
			startTask(driveTask);
		if(getTaskState(manualLift) == taskStateStopped)
			startTask(manualLift);
		if(getTaskState(pneumatics) == taskStateStopped)
			startTask(pneumatics);
		if (getTaskState(claw) == taskStateStopped)
			startTask(claw);
	}
}
