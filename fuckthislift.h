#define liftBtn vexRT(Btn6U)

//Target Values
int potValues[2] = {355, 200};
int potIndex = 0;
float liftPower = 0.0;
float currentPot;

void setMotors(float power)
{
	motor[rightBotLift] = power;
	motor[rightMidLift] = power;
	motor[rightTopLift] = power;
	motor[leftBotLift] = power;
	motor[leftMidLift] = power;
	motor[leftTopLift] = power;
}


task fuckthislift()
{
	currentPot = SensorValue[liftPot];

	if (liftBtn)
	{
		potIndex = (potIndex == 0) ? 1: 0; //allows you to toggle the potIndex
	}

	if (currentPot > potValues[potIndex])
	{
		setMotors(100);
	}
	else if (currentPot < potValues[potIndex])
	{
		setMotors(-100);
	}
	else
	{
		setMotors(0);
}


}
