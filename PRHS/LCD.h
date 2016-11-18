const short leftbutton= 1;
const short centerbutton= 2;
const short rightbutton= 4;

int count = 0;

void waitforpress()
{
	while(nLCDButtons == 0){}
	wait1Msec (5);
}

void waitforrelease()
{
	while(nLCDButtons != 0){}
	wait1Msec (5);
}


task preAutonTask()
{
	bLCDBacklight= true;

	clearLCDLine(0);
	clearLCDLine(1);

	//allows robot to restart from vexnet disconnect without reselecting autonomous code
	while( (nLCDButtons != kButtonCenter)  && bIfiRobotDisabled )
	{
		switch(count){
		case 0:
			displayLCDCenteredString(0, "No Autonomous");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitforpress();

			if (nLCDButtons == centerbutton)
			{
				waitforrelease();
				displayLCDCenteredString(0, "?No Auton?");
				displayLCDCenteredString(1, "||YES||");
				wait1Msec (1000);
				waitforpress();
			}
			if(nLCDButtons == leftbutton)
			{
				waitforrelease();
				count = 3;
			}
			else if(nLCDButtons == rightbutton)
			{
				waitforrelease();
				count++;
			}
			break;
		case 1:
			displayLCDCenteredString(0, "Blue Hang");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitforpress();

			if (nLCDButtons == centerbutton)
			{
				waitforrelease();
				displayLCDCenteredString(0, "Blue Hang???");
				displayLCDCenteredString(1, "||YES||");
				wait1Msec (1000);
				waitforpress();
			}
			if(nLCDButtons == leftbutton)
			{
				waitforrelease();
				count--;
			}
			else if(nLCDButtons == rightbutton)
			{
				waitforrelease();
				count++;
			}
			break;
		case 2:
			displayLCDCenteredString(0, "Blue Near");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitforpress();

			if (nLCDButtons == centerbutton)
			{
				waitforrelease();
				displayLCDCenteredString(0, "Blue Near???");
				displayLCDCenteredString(1, "||YES||");
				wait1Msec (1000);
				waitforpress();
			}
			if(nLCDButtons == leftbutton)
			{
				waitforrelease();
				count--;
			}
			else if(nLCDButtons == rightbutton)
			{
				waitforrelease();
				count++;
			}
			break;
		case 3:
			displayLCDCenteredString(0, "Fence");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitforpress();

			if (nLCDButtons == centerbutton)
			{
				waitforrelease();
				displayLCDCenteredString(0, "Fence???");
				displayLCDCenteredString(1, "||YES||");
				wait1Msec (1000);
				waitforpress();
			}
			if(nLCDButtons == leftbutton)
			{
				waitforrelease();
				count--;
			}
			else if(nLCDButtons == rightbutton)
			{
				waitforrelease();
				count = 0;
			}
			break;

		default:
			displayLCDCenteredString(0, "No valid choice");
			displayLCDCenteredString(1, "was made!");
			break;

		}
	}
}

task autonTask()
{

	{
		bLCDBacklight= true;
		clearLCDLine(0);
		clearLCDLine(1);

		switch(count){

			/////////////////////////////////////////////////////////////////////////////////

		case 0:
			displayLCDCenteredString(0, "No autonomous");
			displayLCDCenteredString(1, "is running!");
			wait1Msec(100);
			break;

			//////////////////////////////////////////////////////////////////////////////////////

		case 1:
			displayLCDCenteredString(0, "Blue Hang");
			displayLCDCenteredString(1, "is running!");
			wait1Msec(100);



			break;

			///////////////////////////////////////////////////////////////////////////////////////

		case 2:
			displayLCDCenteredString(0, "Blue Near");
			displayLCDCenteredString(1, "is running!");
			wait1Msec(100);

			liftUp(450);
			wait(50);
			//backward(127,25);
			wait(50);
			forward(127,500);
			wait(50);
			backward(127, 150);
			wait(50);
			leftturn(127, 50);
			wait(50);
			backward(127,550);
			wait(100);
			//rightturn(127, 10);


			break;
			/////////////////////////////////////////////////////////////////////////////////////////////

		case 3:
			displayLCDCenteredString(0, "Fence");
			displayLCDCenteredString(1, "is running!");
			wait1Msec(100);



			break;


		}
	}
}
