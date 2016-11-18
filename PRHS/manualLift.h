task manualLift()
{
	while(true)
	{
		if(vexRT(Btn6D))
		{
			motor[rightBotLift] = 100;
			motor[rightMidLift] = 100;
			motor[rightTopLift] = 100;
			motor[leftBotLift] = 100;
			motor[leftMidLift] = 100;
			motor[leftTopLift] = 100;
		}

		else if(vexRT(Btn6U))
		{
			motor[rightBotLift] = -100;
			motor[rightMidLift] = -100;
			motor[rightTopLift] = -100;
			motor[leftBotLift] = -100;
			motor[leftMidLift] = -100;
			motor[leftTopLift] = -100;
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

	}
}
