void forward()
{
	motor[leftDrive] = 90;
	motor[rightFront] = 90;
	motor[rightBack] = 90;
}

void backward(int time)
{
	motor[leftDrive] = -90;
	motor[rightFront] = -90;
	motor[rightBack] = -90;
	wait1Msec(time);
}

void lift(int time)
{
			motor[rightBotLift] = -40;
			motor[rightMidLift] = -40;
			motor[rightTopLift] = -40;
			motor[leftBotLift] = -40;
			motor[leftMidLift] = -40;
			motor[leftTopLift] = -40;
			wait1Msec(time);
			motor[rightBotLift] = 0;
			motor[rightMidLift] = 0;
			motor[rightTopLift] = 0;
			motor[leftBotLift] = 0;
			motor[leftMidLift] = 0;
			motor[leftTopLift] = 0;

}

void liftDown(int time)
{
			motor[rightBotLift] = 100;
			motor[rightMidLift] = 100;
			motor[rightTopLift] = 100;
			motor[leftBotLift] = 100;
			motor[leftMidLift] = 100;
			motor[leftTopLift] = 100;
			wait1Msec(time);
}

void stopMotors()
{			motor[rightBotLift] = 0;
			motor[rightMidLift] = 0;
			motor[rightTopLift] = 0;
			motor[leftBotLift] = 0;
			motor[leftMidLift] = 0;
			motor[leftTopLift] = 0;
			motor[leftDrive] = 0;
			motor[rightBack] = 0;
			motor[rightFront] = 0;
}

task auton()
{
	forward();
	wait1Msec(400);
	backward(100);
	lift(1200);
	forward();
	wait10Msec(200);
	stopMotors();


}
