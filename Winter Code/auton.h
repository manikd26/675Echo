void forward(int speed, int distance)
{
	nMotorEncoder[leftDrive] = 0;
	nMotorEncoder[rightDrive] = 0;
	wait1Msec(100);

	while((abs(nMotorEncoder[rightDrive]) < distance) || (abs(nMotorEncoder[leftDrive]) < distance))
	{
		motor[rightDrive] = speed;
		motor[leftDrive] = speed;
	}

	//Brief brake to stop some drift
	motor[rightDrive] = 5;
	motor[leftDrive] = 5;
	wait1Msec(250);
}

//////////////////////////////////////////////////

void backward(int speed, int distance)
{
	nMotorEncoder[leftDrive] = 0;
	nMotorEncoder[rightDrive] = 0;
	wait1Msec(100);

	while((abs(nMotorEncoder[rightDrive]) < distance) || (abs(nMotorEncoder[leftDrive]) < distance))
	{
		motor[rightDrive] = -speed;
		motor[leftDrive] = -speed;
	}

	//Brief brake to stop some drift
	motor[rightDrive] = 5;
	motor[leftDrive] = 5;
	wait1Msec(250);
}

//////////////////////////////////////////////////

void forwardgyro(int speed, int distance, int heading)
{
	nMotorEncoder[leftDrive] = 0;
	nMotorEncoder[rightDrive] = 0;
	wait1Msec(100);

	while((abs(nMotorEncoder[leftDrive]) < distance) || (abs(nMotorEncoder[rightDrive]) < distance))
	{
		motor[leftDrive] = speed;
		motor[rightDrive] = speed;

		if (abs(SensorValue[Gyro]) > (heading*10)+5)
		{
			motor[rightDrive] = speed;
			motor[leftDrive] = speed*0.8;
		}
	}

	//Brief brake to stop some drift
	motor[rightDrive] = -5;
	motor[leftDrive] = -5;
	wait1Msec(250);
}

//////////////////////////////////////////////////

void backwardgyro(int speed, int distance, int heading)
{
	nMotorEncoder[leftDrive] = 0;
	nMotorEncoder[rightDrive] = 0;
	wait1Msec(100);

	while((abs(nMotorEncoder[leftDrive]) < distance) || (abs(nMotorEncoder[rightDrive]) < distance))
	{
		motor[rightDrive] = -speed;
		motor[leftDrive] = -speed;

		if(abs(SensorValue[Gyro]) < (heading*10)-5)
		{
			motor[rightDrive] = -speed*0.8;
			motor[leftDrive] = -speed;
		}

		else if (abs(SensorValue[Gyro]) > (heading*10)+5)
		{
			motor[rightDrive] = -speed;
			motor[leftDrive] = -speed*0.8;
		}
	}
	//Brief brake to stop some drift
	motor[rightDrive] = -5;
	motor[leftDrive] = -5;
	wait1Msec(250);
}

//////////////////////////////////////////////////

void rightturn(int speed, int heading)
{
	while(abs(SensorValue[Gyro]) > heading*10)
	{
		//...continue turning
		motor[rightDrive] = -speed;
		motor[leftDrive] = speed;
	}

	//Brief brake to stop some drift
	motor[rightDrive] = 5;
	motor[leftDrive] = -5;
	SensorValue[Gyro] = 0;
	wait1Msec(250);
}

//////////////////////////////////////////////////

void leftturn(int speed, int heading)
{
	while(abs(SensorValue[Gyro]) < heading*10)
	{
		//...continue turning
		motor[rightDrive] = speed;
		motor[leftDrive] = -speed;
	}

	//Brief brake to stop some drift
	motor[rightDrive] = -5;
	motor[leftDrive] = 5;
	SensorValue[Gyro] = 0;
	wait1Msec(250);
}

//////////////////////////////////////////////////

void liftUp(int targetPot)
{
	while (SensorValue[liftPot] < targetPot)
	{
		motor[leftMidLift] = 127;
		motor[leftTopLift] = 127;
		motor[rightMidLift] = 127;
		motor[rightTopLift] = 127;
	}

	motor[leftMidLift] = 0;
	motor[leftTopLift] = 0;
	motor[rightMidLift] = 0;
	motor[rightTopLift] = 0;
	wait1Msec (250);
}

//////////////////////////////////////////////////

void liftDown(int targetPot)
{
	while (SensorValue[liftPot] > targetPot)
	{
		motor[leftMidLift] = -127;
		motor[leftTopLift] = -127;
		motor[rightMidLift] = -127;
		motor[rightTopLift] = -127;
	}

	motor[leftMidLift] = 0;
	motor[leftTopLift] = 0;
	motor[rightMidLift] = 0;
	motor[rightTopLift] = 0;
	wait1Msec (250);
}

//////////////////////////////////////////////////

void wait(int time)
{
	motor[rightDrive] = 0;
	motor[leftDrive] = 0;
	motor[leftMidLift] = 0;
	motor[leftTopLift] = 0;
	motor[rightMidLift] = 0;
	motor[rightTopLift] = 0;
	wait1Msec(time);
}

//////////////////////////////////////////////////

void openClaw()
{
	SensorValue[pistonClaw] = 1;
}

void closeClaw()
{
	SensorValue[pistonClaw] = 0;
}

void shootLaunch(int time)
{
	SensorValue[pistonLaunch] = 1;
	wait(time);
}
