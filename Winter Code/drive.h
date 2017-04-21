#define limitBtn vexRT(Btn8D)

int driveThreshold = 20;
bool actuateClaw = false;
bool actuateLaunch = false;

int limit;
bool limitBool = true;
bool lastLimitBtn = false;


task driveTask()
{

	if (limitBtn && !lastLimitBtn)
	{
		limitBool = !limitBool;
		lastLimitBtn = true;
	}

	if (limitBtn == 0)
		lastLimitBtn = false;

		if (limitBool == true)
		{
			limit = 127;
		}
		else
		{
			limit = 80;
		}



	if(abs(vexRT(Ch3)) > driveThreshold)
	{
		motor[leftFront] = vexRT(Ch3);
		motor[leftBack] = vexRT(Ch3);

		if ((motor[leftFront]) > 100)
		{
			motor[leftFront] = limit;
			motor[leftBack] = limit;
		}
		else if ((motor[leftFront]) < -100)
		{
			motor[leftFront] = -limit;
			motor[leftBack] = -limit;
		}



	}
	else
	{
		motor[leftFront] = 0;
		motor[leftBack] = 0;

	}

	if(abs(vexRT(Ch2)) > driveThreshold)
	{
		motor[rightFront] = vexRT(Ch2);
		motor[rightBack] = vexRT(Ch2);

		if ((motor[rightFront]) > 100)
		{
			motor[rightFront] = limit;
			motor[rightBack] = limit;
		}
		else if ((motor[rightFront]) < -100)
		{
			motor[rightFront] = -limit;
			motor[rightBack] = -limit;
		}
	}
	else
	{
		motor[rightFront] = 0;
		motor[rightBack] = 0;
	}
}
