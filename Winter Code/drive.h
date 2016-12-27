int driveThreshold = 20;
bool actuateClaw = false;
bool actuateLaunch = false;


task driveTask()
{
	if(abs(vexRT(Ch3)) > driveThreshold)
	{
		motor[leftFront] = vexRT(Ch3);
		motor[leftBack] = vexRT(Ch3);
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
	}
	else
	{
		motor[rightFront] = 0;
		motor[rightBack] = 0;
	}
}

task pneumatics()
{
	while(true)
	{
		if(vexRT[Btn8D] != actuateClaw)
		{
			actuateClaw = !actuateClaw;
			if(actuateClaw)
				SensorValue[pistonClaw] = !SensorValue[pistonClaw];
		}

		if(vexRT[Btn8R] != actuateLaunch)
		{
			actuateLaunch = !actuateLaunch;
			if(actuateLaunch)
				SensorValue[pistonLaunch] = !SensorValue[pistonLaunch];
		}

	}
}
