
task CSLeftDrive()
{
	forward(127, 400); // 450
	wait1Msec(250);
	leftTurn(-127, 40);
	wait1Msec(250);
	forward(127, 650);
	wait1Msec(1000);
	forward(127, 200);
	wait1Msec(250);
	leftTurn(-127, 95);
	wait1Msec(250);
	backward(127, 500);
	wait1Msec(2250);
	forward(127, 1000);
	wait1Msec(1000);
	backward(127, 1000);


}

task CSLeftClaw()
{
	//clawFunction(800);
	wait1Msec(2000);
	clawFunction(400);
	clawHold(1000);
	wait1Msec(1500);
	clawFunction(1000);
	wait1Msec(1500);
	clawFunction(300);
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
	wait1Msec(1250); //1750
	liftUp(2100); //2000
	wait1Msec(250);
	liftDown(550);
	wait1Msec(2000);
	liftUp(2100); //2000
}

/////////////////////////////////////////////////////////////////////////////////

task CSRightDrive()
{
	forward(127, 400); // 450
	wait1Msec(250);
	leftTurn(127, 40);
	wait1Msec(250);
	forward(127, 650);
	wait1Msec(1000);
	forward(127, 200);
	wait1Msec(250);
	leftTurn(127, 95);
	wait1Msec(250);
	backward(127, 500);
	wait1Msec(2250);
	forward(127, 1000);
	wait1Msec(1000);
	backward(127, 1000);
}

task CSRightClaw()
{
	wait1Msec(2000);
	clawFunction(400);
	clawHold(1000);
	wait1Msec(1500);
	clawFunction(1000);
	wait1Msec(2500);
	clawFunction(300);
	clawHold(1000);
	wait1Msec(500);
	clawFunction(1000);
}

task CSRightLift()
{
	wait1Msec(3600);
	liftUp(1500);
	wait1Msec(1250);
	liftUp(2100); //2000
	wait1Msec(250);
	liftDown(550);
	wait1Msec(2000);
	liftUp(2100); //2000
}

/////////////////////////////////////////////////////////////////////////////////

task CSLeftBlDrive()
{
	forward(127, 400); // 450
	wait1Msec(250);
	leftTurn(-127, 40);
	wait1Msec(250);
	forward(127, 650);
	wait1Msec(1000);
	forward(127, 200);
	wait1Msec(250);
	leftTurn(-127, 95);
	wait1Msec(250);
	backward(127, 500);
}

task CSLeftBlClaw()
{
	wait1Msec(2000);
	clawFunction(400);
	clawHold(1000);
	wait1Msec(1500);
	clawFunction(1000);
}

task CSLeftBlLift()
{
	wait1Msec(3600);
	liftUp(1500);
	wait1Msec(1250);
	liftUp(2100); //2000
}

/////////////////////////////////////////////////////////////////////////////////

task CSRightBlDrive()
{
	forward(127, 400); // 450
	wait1Msec(250);
	leftTurn(127, 40);
	wait1Msec(250);
	forward(127, 650);
	wait1Msec(1000);
	forward(127, 200);
	wait1Msec(250);
	leftTurn(127, 95);
	wait1Msec(250);
	backward(127, 500);
}

task CSRightBlClaw()
{
	wait1Msec(2000);
	clawFunction(400);
	clawHold(1000);
	wait1Msec(1500);
	clawFunction(1000);

}

task CSRightBlLift()
{
	wait1Msec(3600);
	liftUp(1500);
	wait1Msec(1250);
	liftUp(2100); //2000

}
