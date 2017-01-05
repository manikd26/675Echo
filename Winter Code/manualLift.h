float baseClaw;

task manualLift()
{
	while(true)
	{
		if(vexRT(Btn6U))
		{
			motor[rightMidLift] = 127;
			motor[rightTopLift] = 127;
			motor[leftMidLift] = 127;
			motor[leftTopLift] = 127;
		}

		else if(vexRT(Btn6D))
		{
			motor[rightMidLift] = -127;
			motor[rightTopLift] = -127;
			motor[leftMidLift] = -127;
			motor[leftTopLift] = -127;
		}

		else
		{
			motor[rightMidLift] = 0;
			motor[rightTopLift] = 0;
			motor[leftMidLift] = 0;
			motor[leftTopLift] = 0;
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
	}
}

task adjustClaw()
{
	SensorValue[rightClawPot] = baseClaw;

	while(SensorValue[leftClawPot] < baseClaw)
		motor[leftClaw] = 127;

	while(SensorValue[leftClawPot] > baseClaw)
		motor[leftClaw] = -127;

	while(SensorValue[leftClawPot] == baseClaw)
		motor[leftClaw] = 0;

	wait1Msec(40);
}
