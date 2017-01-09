float baseClaw;
bool mrParsonSucks = true;
task manualLift()
{
	while(true)
	{
		if(vexRT(Btn6U))
		{
			motor[rightBotLift] = 127;
			motor[rightMidLift] = 127;
			motor[rightTopLift] = 127;
			motor[leftBotLift] = 127;
			motor[leftMidLift] = 127;
			motor[leftTopLift] = 127;
		}

		else if(vexRT(Btn6D))
		{
			motor[rightBotLift] = -127;
			motor[rightMidLift] = -127;
			motor[rightTopLift] = -127;
			motor[leftBotLift] = -127;
			motor[leftMidLift] = -127;
			motor[leftTopLift] = -127;
		}

		else
		{
			motor[rightBotLift] = 0;
			motor[rightMidLift] = 0;
			motor[rightTopLift] = 0;
			motor[leftBotLift] = 0;
			motor[leftMidLift] = 0;
			motor[leftTopLift] = 0;
		}

		if (vexRT(Btn8D))
		{
			while (SensorValue[liftPot] < 1300)
			{
				motor[rightBotLift] = 127;
				motor[rightMidLift] = 127;
				motor[rightTopLift] = 127;
				motor[leftBotLift] = 127;
				motor[leftMidLift] = 127;
				motor[leftTopLift] = 127;
			}
		}

		while (SensorValue[liftPot] < 575)
		{
			if (vexRT(Btn6D))
			{
				motor[rightBotLift] = 0;
				motor[rightMidLift] = 0;
				motor[rightTopLift] = 0;
				motor[leftBotLift] = 0;
				motor[leftMidLift] = 0;
				motor[leftTopLift] = 0;
			}
			else if (vexRT(Btn6U))
			{
				motor[rightBotLift] = 127;
				motor[rightMidLift] = 127;
				motor[rightTopLift] = 127;
				motor[leftBotLift] = 127;
				motor[leftMidLift] = 127;
				motor[leftTopLift] = 127;
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
			motor[rightClaw] = 105;
			motor[leftClaw] = 105;
		}
		else if (vexRT(Btn5D))
		{
			motor[rightClaw] = -105;
			motor[leftClaw] = -105;
		}
		else
		{
			motor[rightClaw] = 0;
			motor[leftClaw]= 0;
		}

		if (SensorValue[liftPot] > 1900 && mrParsonSucks)
		{
			motor[rightClaw] = -105;
			motor[leftClaw] = -105;
			wait1Msec(650);
			mrParsonSucks = false;
		}
		if (SensorValue[liftPot] < 1900) {
			mrParsonSucks = true;
		}

	}
}
