#pragma config(Motor,  port1,           rightBtmLift,  tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightMidLift,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightTopLift,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftMidLift,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftTopLift,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          leftBtmLift,   tmotorVex393_HBridge, openLoop)

#pragma platform(VEX2)

#pragma competitionControl(Competition)

#include "Vex_Competition_Includes.c"

#include "drive.h"


void pre_auton()
{

  bStopTasksBetweenModes = true;

}

task autonomous()
{

  AutonomousCodePlaceholderForTesting();
}


task usercontrol()
{

  while (true)
  {

    UserControlCodePlaceholderForTesting();
  }
}
