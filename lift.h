
task moveLift()
{

	if(vexRT(Btn6U))
	{
		motor[leftBotLift] = 127;
		motor[leftMidLift] = 127;
		motor[leftTopLift] = 127;
		motor[rightBotLift] = 127;
		motor[rightMidLift] = 127;
		motor[rightTopLift] = 127;
	}

	else if(vexRT(Btn6D))
	{
		motor[leftBotLift] = -127;
		motor[leftMidLift] = -127;
		motor[leftTopLift] = -127;
		motor[rightBotLift] = -127;
		motor[rightMidLift] = -127;
		motor[rightTopLift] = -127;
	}

	else
	{
		motor[leftBotLift] = 0;
		motor[leftMidLift] = 0;
		motor[leftTopLift] = 0;
		motor[rightBotLift] = 0;
		motor[rightMidLift] = 0;
		motor[rightTopLift] = 0;
	}

}
