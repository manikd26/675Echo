
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

	}
}
