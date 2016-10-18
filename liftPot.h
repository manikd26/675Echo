#define liftBtn vexRT(Btn6U)

//Target Values
int potValues[2] = {0, 150};
int potIndex = 0;

//TBH Constants
float Kg = 0.00;

//TBH Calculation Variables
float drive;
float driveZero;
long cross;
float driveApprox;

float currentPot;
float error;
float lastError;



void TBHLift(float target)
{
	currentPot = SensorValue[liftPot];
}



task moveLiftPot()
{
	while(true){
		TBHLift(potValues[1]);
	}
}
