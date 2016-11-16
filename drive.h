int driveThreshold = 20;

task driveTask()
{
	if(abs(vexRT(Ch3)) > driveThreshold)	{
		motor[leftDrive] = vexRT(Ch3);
		} else {
		motor[leftDrive] = 0;
	}

	if(abs(vexRT(Ch2)) > driveThreshold)
	{
		motor[rightFront] = vexRT(Ch2);
		motor[rightBack] = vexRT(Ch2);
	}
	else
	{
		motor[rightFront] = 0;
		motor[rightBack] = 0;
	}
}

task hangTask()
{
		if(vexRT(Btn8U))
		{
			motor[hangMotors] = -127;
		}
		else if(vexRT(Btn8D))
		{
			motor[hangMotors] = +127;
		}
		else
		{
			motor[hangMotors] = 0;
		}
}
