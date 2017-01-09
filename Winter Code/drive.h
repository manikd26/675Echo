int driveThreshold = 20;
bool actuateClaw = false;
bool actuateLaunch = false;


task driveTask()
{
	if(abs(vexRT(Ch3)) > driveThreshold)
	{
		motor[leftDrive] = vexRT(Ch3);
	}
	else
	{
		motor[leftDrive] = 0;
	}

	if(abs(vexRT(Ch2)) > driveThreshold)
	{
		motor[rightDrive] = vexRT(Ch2);
	}
	else
	{
		motor[rightDrive] = 0;
	}
}
