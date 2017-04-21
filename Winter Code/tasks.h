
task CSLeftDrive()
{
	forward(127, 400); // 450
	wait1Msec(250);
	leftTurn(-127, 40);
	wait1Msec(250);
	forward(127, 650);
	wait1Msec(1000);
	forward(127, 100);
	wait1Msec(250);
	leftTurn(-127, 60);
	wait1Msec(250);
	backward(127, 500);
	wait1Msec(2250);
	forward(127, 1000);
	wait1Msec(1000);
	backward(127, 1000);


}

task CSLeftClaw()
{
	wait1Msec(2000);
	clawFunction(550);
	clawHold(1500);
	wait(750);
	clawFunction(1350);
	wait(2000);
	clawFunction(300);
	clawHold(1000);
	wait(1000);
	clawFunction(1000);
	wait(3000);
	clawFunction(1000);
	wait(1000);
	clawFunction(400);
	wait(2000);
	clawFunction(1000);

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
	forward(127, 100);
	wait1Msec(250);
	leftTurn(-127, 60);
	wait1Msec(250);
	backward(127, 500);
	wait1Msec(2250);
}

task CSLeftBlClaw()
{
	wait1Msec(2000);
	clawFunction(550);
	clawHold(1500);
	wait(750);
	clawFunction(1350);
	wait(2000);
}

task CSLeftBlLift()
{
	wait1Msec(3600);
	liftUp(1500);
	wait1Msec(1250); //1750
	liftUp(2100); //2000
	wait1Msec(250);
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

//task CSRightBlClaw()
//{
//	wait1Msec(2000);
//	clawFunction(400);
//	clawHold(1000);
//	wait1Msec(1500);
//	clawFunction(1000);

//}

//task CSRightBlLift()
//{
//	wait1Msec(3600);
//	liftUp(1500);
//	wait1Msec(1250);
//	liftUp(2100); //2000
//}


/////////////////////////////////////////////////////////////////////////////////

task FCDrive()
{
	backward(127, 1350);
	leftTurn(127, 10);
}

task FCLift()
{
	wait1Msec(2500);
	liftUp(2150);
}

task FCClaw()
{
	wait1Msec(1350);
	clawFunction(550);
	wait(250);
	clawFunction(1350);
}





/**
task PSDrive()
{
backward(127, 300);
wait1Msec(500);
forward(127, 240);
wait1Msec(1500);
backward(127, 800);
wait1Msec(500)
backward(60, 25);
wait1Msec(2000);
forward(127, 900);
leftTurn(90, 6.5);//
wait1Msec(500);
backward(127, 800);
wait1Msec(500);
forward(127, 25);
backward(60, 50);
wait1Msec(500);
forward(127, 900);
leftTurn(90, 6.5);//
wait1Msec(1000);
backward(127, 800);
wait1Msec(1000);
forward(127, 550);
wait1Msec(250);
leftTurn(127, 45);
wait1Msec(250);
forward(127, 600);
wait1Msec(500);
forward(127, 600);
wait1Msec(500);
leftTurn(-127, 90);
//forward(127, 800);
//backward(127, 800);
}

task PSClaw()
{
clawFunction(800);
wait1Msec(750);
clawFunction(200);
clawHold(1250);
clawFunction(1000);
wait1Msec(250);
clawFunction(1000);
wait1Msec(2350); //2150
clawfunction(400);
clawHold(1000);
clawFunction(1000);
wait1Msec(2250); //1750
clawFunction(400);
clawHold(1500);
clawFunction(1000);
wait1Msec(1000);
clawFunction(800);
wait1Msec(1750);
clawFunction(400);
//clawHold(1250);
//clawFunction(800);
//clawFunction(300);
//clawHold(1000);
//clawFunction(800);
//clawFunction(300);
//clawHold(1000);
//clawFunction(800);
}

task PSLift()
{
wait1Msec(3000);
liftUp(2100);
wait1Msec(1000);
liftDown(550);
wait1Msec(1500);
liftUp(2100);
wait1Msec(500);
liftDown(550);
wait1Msec(1500);
liftUp(2100);
wait1Msec(500);
liftDown(550);
wait1Msec(1750);
liftUp(1500);
//liftUp(2100);
//liftDown(550);
//liftUp(2100);
//liftDown(550);
}

**/
