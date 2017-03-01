
task CSLeftDrive()
{
	forward(127, 500);
	wait1Msec(250);
	leftTurn(-127, 40);
	wait1Msec(250);
	forward(127, 650);
	wait1Msec(1000);
	forward(127, 200);
	wait1Msec(250);
	leftTurn(-127, 100);
	wait1Msec(250);
	backward(127, 500);
	wait1Msec(1500);
	forward(127, 900);
	wait1Msec(1000);
	backward(127, 900);
	//backward(127, 550);
	//wait1Msec(1000);
	//forward(127, 700);
	//forward(127, 50);
	//backward(127, 800);


}

task CSLeftClaw()
{
	clawFunction(800);
	wait1Msec(1200);
	clawFunction(400);
	clawHold(1000);
	wait1Msec(2000);
	clawFunction(1000);
	wait1Msec(1500);
	clawFunction(400);
	clawHold(1000);
	wait1Msec(1000);
	clawFunction(1000);
	//wait1Msec(3000);
	//clawFunction(1000);
	//wait1Msec(1000);
	//clawFunction(400);
	//wait1Msec(2000);
	//clawFunction(1000);

}

task CSLeftLift()
{
	wait1Msec(3600);
	liftUp(1500);
	wait1Msec(1500);
	liftUp(1900);
	wait1Msec(250);
	liftDown(550);
	wait1Msec(2000);
	liftUp(1900);
}

/////////////////////////////////////////////////////////////////////////////////

task CSRightDrive()
{

}

task CSRightClaw()
{

}

task CSRightLift()
{

}

/////////////////////////////////////////////////////////////////////////////////

task CSLeftBlDrive()
{
	forward(127, 500);
	wait1Msec(250);
	leftTurn(-127, 40);
	wait1Msec(250);
	forward(127, 650);
	wait1Msec(1000);
	forward(127, 200);
	wait1Msec(250);
	leftTurn(-127, 100);
	wait1Msec(250);
	backward(127, 500);
}

task CSLeftBlClaw()
{
	clawFunction(800);
	wait1Msec(1200);
	clawFunction(400);
	clawHold(1000);
	wait1Msec(2000);
	clawFunction(1000);
}

task CSLeftBlLift()
{
	wait1Msec(3600);
	liftUp(1500);
	wait1Msec(1500);
	liftUp(1900);
}

/////////////////////////////////////////////////////////////////////////////////

task CSRightBlDrive()
{

}

task CSRightBlClaw()
{

}

task CSRightBlLift()
{

}
