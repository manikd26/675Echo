task manualLift()
{
	while(true)
	{
		if(vexRT(Btn6U))
		{
			motor[rightMidLift] = 100;
			motor[rightTopLift] = 100;
			motor[leftMidLift] = 100;
			motor[leftTopLift] = 100;
		}

		else if(vexRT(Btn6D)
		{
			motor[rightMidLift] = -100;
			motor[rightTopLift] = -100;
			motor[leftMidLift] = -100;
			motor[leftTopLift] = -100;
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
		if (vexRT(Btn5U)
		{
			motor[rightClaw] = 127;
			motor[leftClaw] = 127;
		}
		else if (vexRT(Btn5D)
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
