void forward(int speed, int distance)
{
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[rightFront] = 0;
	wait1Msec(100);

	while((abs(nMotorEncoder[rightFront]) < distance) || (abs(nMotorEncoder[leftFront]) < distance))
	{
		motor[rightFront] = speed;
		motor[leftFront] = speed;
		motor[rightBack] = speed;
		motor[leftBack] = speed;
	}

	//Brief brake to stop some drift
	motor[rightFront] = -5;  //-5
	motor[leftFront] = -5;
	motor[leftBack] = -5;
	motor[rightBack] = -5;
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
		motor[rightFront] = -speed;
		motor[leftFront] = -speed;
		motor[rightBack] = -speed;
		motor[leftBack] = -speed;

	}

	//Brief brake to stop some drift
	motor[rightFront] = 5;
	motor[leftFront] = 5;
	motor[leftBack] = 5;
	motor[rightBack] = 5;
	wait1Msec(250);
}

////////////////////////////////////////////////// fix motors from here down

void forwardgyro(int speed, int distance, int heading)
{
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[rightFront] = 0;
	wait1Msec(100);

	while((abs(nMotorEncoder[leftFront]) < distance) || (abs(nMotorEncoder[rightFront]) < distance))
	{
		motor[rightFront] = speed;
		motor[leftFront] = speed;
		motor[rightBack] = speed;
		motor[leftBack] = speed;

		if (abs(SensorValue[Gyro]) < (heading*10)+5)
		{
			motor[rightFront] = speed*0.8;
			motor[rightBack] = speed*0.8;
			motor[leftBack] = speed;
			motor[leftFront] = speed;
		}
		else if (abs(SensorValue[Gyro]) > (heading*10)+5)
		{
			motor[rightFront] = speed;
			motor[rightBack] = speed;
			motor[leftBack] = speed*0.8;
			motor[leftFront] = speed*0.8;
		}
	}

	//Brief brake to stop some drift
	motor[rightFront] = -5;
	motor[leftFront] = -5;
	motor[leftBack] = -5;
	motor[rightBack] = -5;
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
		motor[rightFront] = -speed;
		motor[leftFront] = -speed;
		motor[rightBack] = -speed;
		motor[leftBack] = -speed;

		if(abs(SensorValue[Gyro]) < (heading*10)-5)
		{
			motor[rightFront] = -speed*0.8;
			motor[rightBack] = -speed*0.8;
			motor[leftFront] = -speed;
			motor[leftBack] = -speed;
		}

		else if (abs(SensorValue[Gyro]) > (heading*10)+5)
		{
			motor[rightFront] = -speed;
			motor[rightBack] = -speed;
			motor[leftFront] = -speed*0.8;
			motor[leftBack] = -speed*0.8;
		}
	}
	//Brief brake to stop some drift
	motor[rightFront] = -5;
	motor[leftFront] = -5;
	motor[leftBack] = -5;
	motor[rightBack] = -5;
	wait1Msec(250);
}

//////////////////////////////////////////////////

void rightTurn(int speed, int heading)
{
	while(abs(SensorValue[Gyro]) > heading*10)
	{
		//...continue turning
		motor[rightFront] = -speed;
		motor[rightBack] = -speed;
		motor[leftFront] = speed;
		motor[leftBack] = speed;
	}

	//Brief brake to stop some drift
	motor[rightFront] = 5;
	motor[rightBack] = 5;
	motor[leftFront] = -5;
	motor[leftBack] = -5;
	SensorValue[Gyro] = 0;
	wait1Msec(250);
}

//////////////////////////////////////////////////

void leftTurn(int speed, int heading)
{
	while(abs(SensorValue[Gyro]) < heading*10)
	{
		//...continue turning
		motor[rightFront] = speed;
		motor[rightBack] = speed;
		motor[leftFront] = -speed;
		motor[leftBack] = -speed;
	}

	//Brief brake to stop some drift
	motor[rightFront] = -5;
	motor[rightBack] = -5;
	motor[leftFront] = 5;
	motor[leftBack] = 5;
	SensorValue[Gyro] = 0;
	wait1Msec(250);
}

//////////////////////////////////////////////////

void liftUp(int targetPot)
{
	while (SensorValue[liftPot] < targetPot)
	{
		motor[rightMidLift] = 127;
		motor[leftMidLift] = 127;
		motor[rightLift] = 127;
		motor[leftLift] = 127;
	}


	motor[rightMidLift] = -5;
	motor[leftMidLift] = -5;
	motor[rightLift] = -5;
	motor[leftLift] = -5;
	wait1Msec (500);
}

//////////////////////////////////////////////////
void liftUpPot(int targetPot)
{
	while (SensorValue[liftPot] < targetPot)
	{
		motor[rightMidLift] = 127;
		motor[leftMidLift] = 127;
		motor[rightLift] = 127;
		motor[leftLift] = 127;
	}

	if (SensorValue[liftPot] > targetPot)
	{
		motor[rightClaw] = -127;
		motor[leftClaw] = -127;
		wait1Msec(650);
	}

	motor[rightMidLift] = 0;
	motor[leftMidLift] = 0;
	motor[rightLift] = 0;
	motor[leftLift] = 0;
	wait1Msec (250);
}

//////////////////////////////////////////////////

void liftDown(int targetPot)
{
	while (SensorValue[liftPot] > targetPot)
	{
		motor[rightMidLift] = -127;
		motor[leftMidLift] = -127;
		motor[rightLift] = -127;
		motor[leftLift] = -127;
	}

	motor[rightMidLift] = 0;
	motor[leftMidLift] = 0;
	motor[rightLift] = 0;
	motor[leftLift] = 0;
	wait1Msec(250);
}

//////////////////////////////////////////////////

void openClaw(int targetPot)
{
	while (SensorValue[clawPot] < targetPot)
	{
		motor[rightClaw] = 127;
		motor[leftClaw] = 127;
	}

	motor[rightClaw] = -5;
	motor[leftClaw] = -5;

	wait1Msec(250);

}

//////////////////////////////////////////////////

void closeClaw(int targetPot)
{
	while (SensorValue[clawPot] > targetPot)
	{
		motor[rightClaw] = -127;
		motor[leftClaw] = -127;
	}

	motor[rightClaw] = 5;
	motor[leftClaw] = 5;

	wait1Msec(250);
}

//////////////////////////////////////////////////

void clawFunction(int targetPot)
{
	while (SensorValue[clawPot] < targetPot)
	{
		motor[rightClaw] = -127;
		motor[leftClaw] = -127;
	}
	while (SensorValue[clawPot] > targetPot)
	{
		motor[rightClaw] = 127;
		motor[leftClaw] = 127;
	}

	motor[rightClaw] = -20;
	motor[leftClaw] = -20;

	wait1Msec(1000);


}

void clawHold(int time)
{
	motor[rightClaw] = 60;
	motor[leftClaw] = 60;

	wait1Msec(time);
}

//////////////////////////////////////////////////

void wait(int time)
{
	wait1Msec(time);
}

//////////////////////////////////////////////////

void driveFAndLift(int speed, int distance, int targetPot)
{
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[rightFront] = 0;
	wait1Msec(100);


	while(((abs(nMotorEncoder[rightFront]) < distance) || (abs(nMotorEncoder[leftFront]) < distance)))
	{
		motor[rightFront] = speed;
		motor[leftFront] = speed;
		motor[rightBack] = speed;
		motor[leftBack] = speed;

		while (SensorValue[liftPot] < targetPot)
		{
			motor[rightMidLift] = 127;
			motor[leftMidLift] = 127;
			motor[rightLift] = 127;
			motor[leftLift] = 127;

		}
	}

	motor[rightFront] = -5;
	motor[leftFront] = -5;
	motor[rightBack] = -5;
	motor[leftBack] = -5;

	motor[rightMidLift] = -15;
	motor[rightLift] = -15;
	motor[leftMidLift] = -15;
	motor[leftLift] = -15;

	wait1Msec(500);
}

//////////////////////////////////////////////////

void driveAndClaw(int speed, int distance, int targetPot)
{
	while((abs(nMotorEncoder[rightFront]) < distance) || (abs(nMotorEncoder[leftFront]) < distance))
	{
		motor[rightFront] = speed;
		motor[leftFront] = speed;
		motor[rightBack] = speed;
		motor[leftBack] = speed;
	}

	while((abs(nMotorEncoder[rightFront]) > distance) || (abs(nMotorEncoder[leftFront]) > distance))
	{
		motor[rightFront] = -speed;
		motor[leftFront] = -speed;
		motor[rightBack] = -speed;
		motor[leftBack] = -speed;
	}

	clawFunction(targetPot);
}
