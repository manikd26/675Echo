void forward(int speed, int distance)
{
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[rightFront] = 0;
	wait1Msec(100);

	while((abs(nMotorEncoder[rightFront]) < distance) || (abs(nMotorEncoder[leftFront]) < distance))
	{
		motor[rightBack] = speed;
		motor[rightFront] = speed;
		motor[leftBack] = speed;
		motor[leftFront] = speed;
	}

	//Brief brake to stop some drift
	motor[rightBack] = 5;
	motor[rightFront] = 5;
	motor[leftBack] = 5;
	motor[leftFront] = 5;
	wait1Msec(250);
}

//////////////////////////////////////////////////

void backward(int speed, int distance)
{
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[rightFront] = 0;
	wait1Msec(100);

	while((abs(nMotorEncoder[rightFront]) < distance) || (abs(nMotorEncoder[leftFront]) < distance))
	{
		motor[rightBack] = -speed;
		motor[rightFront] = -speed;
		motor[leftBack] = -speed;
		motor[leftFront] = -speed;
	}

	//Brief brake to stop some drift
	motor[rightBack] = 5;
	motor[rightFront] = 5;
	motor[leftBack] = 5;
	motor[leftFront] = 5;
	wait1Msec(250);
}

//////////////////////////////////////////////////

void forwardgyro(int speed, int distance, int heading)
{
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[rightFront] = 0;
	wait1Msec(100);

	while((abs(nMotorEncoder[leftFront]) < distance) || (abs(nMotorEncoder[rightFront]) < distance)
	{
		motor[leftBack] = speed;
		motor[leftFront] = speed;
		motor[rightBack] = speed;
		motor[rightFront] = speed;

		if (abs(SensorValue[Gyro]) > (heading*10)+5)
		{
			motor[rightBack] = speed;
			motor[rightFront] = speed;
			motor[leftBack] = speed*0.8;
			motor[leftFront] = speed*0.8;
		}
	}

	//Brief brake to stop some drift
	motor[rightBack] = 05;
	motor[rightFront] = -5;
	motor[leftBack] = -5;
	motor[leftFront] = -5;
	wait1Msec(250);
}

//////////////////////////////////////////////////

void backwardgyro(int speed, int distance, int heading)
{
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[rightFront] = 0;
	wait1Msec(100);

	while((abs(nMotorEncoder[leftFront]) < distance) || (abs(nMotorEncoder[rightFront]) < distance))
	{
		motor[rightBack] = -speed;
		motor[rightFront] = -speed;
		motor[leftBack] = -speed;
		motor[leftFront] = -speed;

		if(abs(SensorValue[Gyro]) < (heading*10)-5)
		{
			motor[rightBack] = -speed*0.8;
			motor[rightFront] = -speed*0.8;
			motor[leftBack] = -speed;
			motor[leftFront] = -speed;
		}

		else if (abs(SensorValue[Gyro]) > (heading*10)+5)
		{
			motor[rightBack] = -speed;
			motor[rightFront] = -speed;
			motor[leftBack] = -speed*0.8;
			motor[leftFront] = -speed*0.8;
		}
	}
	//Brief brake to stop some drift
	motor[rightBack] = -5;
	motor[rightFront] = -5;
	motor[leftBack] = -5;
	motor[leftFront] = -5;
	wait1Msec(250);
}

//////////////////////////////////////////////////

void rightturn(int speed, int heading)
{
	while(abs(SensorValue[Gyro]) > heading*10)
	{
		//...continue turning
		motor[rightBack] = -speed;
		motor[rightFront] = -speed;
		motor[leftBack] = speed;
		motor[leftFront] = speed;
	}

	//Brief brake to stop some drift
	motor[rightBack] = 5;
	motor[rightFront] = 5;
	motor[leftBack] = -5;
	motor[leftFront] = -5;
	SensorValue[Gyro] = 0;
	wait1Msec(250);
}

//////////////////////////////////////////////////

void leftturn(int speed, int heading)
{
	while(abs(SensorValue[Gyro]) < heading*10)
	{
		//...continue turning
		motor[rightBack] = speed;
		motor[rightFront] = speed;
		motor[leftBack] = -speed;
		motor[leftFront] = -speed;
	}

	//Brief brake to stop some drift
	motor[rightBack] = -5;
	motor[rightFront] = -5;
	motor[leftBack] = 5;
	motor[leftFront] = 5;
	SensorValue[Gyro] = 0;
	wait1Msec(250);
}

//////////////////////////////////////////////////

void liftUp(int targetPot)
{
	while (SensorValue[liftPot] < targetPot)
	{
		motor[leftBotLift] = 127;
		motor[leftMidLift] = 127;
		motor[leftTopLift] = 127;
		motor[rightBotLift] = 127;
		motor[rightMidLift] = 127;
		motor[rightTopLift] = 127;
	}

	motor[leftBotLift] = 0;
	motor[leftMidLift] = 0;
	motor[leftTopLift] = 0;
	motor[rightBotLift] = 0;
	motor[rightMidLift] = 0;
	motor[rightTopLift] = 0;
	wait1Msec (250);
}

//////////////////////////////////////////////////

void liftDown(int targetPot)
{
	while (SensorValue[liftPot] > targetPot)
	{
		motor[leftBotLift] = -127;
		motor[leftMidLift] = -127;
		motor[leftTopLift] = -127;
		motor[rightBotLift] = -127;
		motor[rightMidLift] = -127;
		motor[rightTopLift] = -127;
	}

	motor[leftBotLift] = 0;
	motor[leftMidLift] = 0;
	motor[leftTopLift] = 0;
	motor[rightBotLift] = 0;
	motor[rightMidLift] = 0;
	motor[rightTopLift] = 0;
	wait1Msec (250);
}

//////////////////////////////////////////////////

void wait(int time)
{
	motor[rightBack] = 0;
	motor[leftBack] = 0;
	motor[rightFront] = 0;
	motor[leftFront] = 0;
	motor[leftBotLift] = 0;
	motor[leftMidLift] = 0;
	motor[leftTopLift] = 0;
	motor[rightBotLift] = 0;
	motor[rightMidLift] = 0;
	motor[rightTopLift] = 0;
	wait1Msec(time);
}

//////////////////////////////////////////////////
