float baseClaw;
bool mrParsonSucks = true;

task manualLift()
{
	while(true)
	{
		if(vexRT(Btn6U))
		{
			motor[rightMidLift] = 127;
			motor[leftMidLift] = 127;
			motor[rightLift] = 127;
			motor[leftLift] = 127;
		}

		else if(vexRT(Btn6D))
		{
			motor[rightMidLift] = -127;
			motor[leftMidLift] = -127;
			motor[rightLift] = -127;
			motor[leftLift] = -127;
		}

		else
		{
			motor[rightMidLift] = 0;
			motor[leftMidLift] = 0;
			motor[rightLift] = 0;
			motor[leftLift] = 0;
		}


		while (SensorValue[liftPot] < 575)
		{
			if (vexRT(Btn6D))
			{
				motor[rightMidLift] = 0;
				motor[leftMidLift] = 0;
				motor[rightLift] = 0;
				motor[leftLift] = 0;
			}
			else if (vexRT(Btn6U))
			{
				motor[rightMidLift] = 127;
				motor[leftMidLift] = 127;
				motor[rightLift] = 127;
				motor[leftLift] = 127;
			}
		}
	}
}

task claw()
{
	while (true)
	{
		if (vexRT(Btn5U))
		{
			motor[rightClaw] = 127;
			motor[leftClaw] = 127;
		}
		else if (vexRT(Btn5D))
		{
			motor[rightClaw] = -127;
			motor[leftClaw] = -127;
		}
		else
		{
			motor[rightClaw] = 0;
			motor[leftClaw]= 0;
		}

		if (SensorValue[liftPot] > 1800 && mrParsonSucks)
		{
			motor[rightClaw] = -127;
			motor[leftClaw] = -127;
			wait1Msec(650);
			mrParsonSucks = false;
		}
		if (SensorValue[liftPot] < 1800) {
			mrParsonSucks = true;
		}



	}
}
