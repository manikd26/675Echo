#define liftBtn vexRT(Btn6U)

//Target Values
int potValues[2] = {355, 200};
int potIndex = 0;
float liftPower = 0.0;

//TBH Constants
float Kg = 0.01;

//TBH Calculation Variables
float drive;
float driveZero;
long cross;
float driveApprox;

float currentPot;
float error;
float lastError;

void sendLiftPower(float power)
{
	int pow = round(power);
	if (pow < 0)
		pow *=-1;
	motor[rightBotLift] = pow;
	motor[rightMidLift] = pow;
	motor[rightTopLift] = pow;
	motor[leftBotLift] = pow;
	motor[leftMidLift] = pow;
	motor[leftTopLift] = pow;

}

void TBHLift(float target)
{
	currentPot = SensorValue[liftPot];

	error = target - currentPot;

	// Use Kp as gain
	drive =  drive + (error * Kg);


	// Clip - we are only going forwards
	if (drive > 1)
		drive = 1;
	if(drive < 0)
		drive = 0;

	// Z-cross LEFT
	if(sgn(error) != sgn(lastError)) {
		// First zero crossing after a new set velocity command
		if(cross) {
			// Set drive to the open loop approximation
			drive = driveApprox;
			cross = 0;
		}
		else
			drive = 0.5 * (drive + driveZero);

		// Save this drive value in the "tbh" variable
		driveZero = drive;
	}

	liftPower = (drive * 127) + 0.5;


	// Save last error
	lastError = error;


	wait1Msec(40); //wait 40 milliseconds for a potential target change, adjust as needed
}

task moveLiftPot()
{
	while(true){
		if (liftBtn) {
			potIndex = (potIndex == 0) ? 1: 0; //allows you to toggle the potIndex
		}
		TBHLift(potValues[potIndex]);
			sendLiftPower(liftPower);
	}
}
