float baseClaw;
bool mrParsonSucks = true;
task manualLift()
{
	while(true)
	{
		if(vexRT(Btn6U))
		{
			motor[rightBotLift] = 105;
			motor[rightMidLift] = 105;
			motor[rightTopLift] = 105;
			motor[leftBotLift] = 105;
			motor[leftMidLift] = 105;
			motor[leftTopLift] = 105;
		}

		else if(vexRT(Btn6D))
		{
			motor[rightBotLift] = -105;
			motor[rightMidLift] = -105;
			motor[rightTopLift] = -105;
			motor[leftBotLift] = -105;
			motor[leftMidLift] = -105;
			motor[leftTopLift] = -105;
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
				motor[rightBotLift] = 105;
				motor[rightMidLift] = 105;
				motor[rightTopLift] = 105;
				motor[leftBotLift] = 105;
				motor[leftMidLift] = 105;
				motor[leftTopLift] = 105;
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

		if (SensorValue[liftPot] > 1800 && mrParsonSucks)
		{
			motor[rightClaw] = -105;
			motor[leftClaw] = -105;
			wait1Msec(650);
			mrParsonSucks = false;
		}
		if (SensorValue[liftPot] < 1800) {
			mrParsonSucks = true;
		}



	}
}
