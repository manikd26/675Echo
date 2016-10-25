#define liftBtn vexRT(Btn6U)

//Target Values
int potValues[2] = {400, 200};
int potIndex = 0;
float liftPower = 0.0;

//PID Constants
float Kp = 0.0012;
float Ki = 0.0;
float Kd = 0.02;

float integralActiveZone = 0.0; //value of rpm after which proportion stops taking effect

float currentPot;
float error;
float lastError;

float proportion;
float integral;
float integralRaw;
float derivative;

void sendLiftPower(float power)
{
	int pow = round(power);
	motor[rightBotLift] = pow;
	motor[rightMidLift] = pow;
	motor[rightTopLift] = pow;
	motor[leftBotLift] = pow;
	motor[leftMidLift] = pow;
	motor[leftTopLift] = pow;
}

void PIDlift(float target)
{
	currentPot = SensorValue[liftPot];

	error = target - currentPot;

	//Proportion
	proportion = Kp*error;

	//Integral
	if (abs(error) < integralActiveZone && error != 0)
	{
		integralRaw = integralRaw + error;
	}
	else //if error is so big and P is still taking effect, raw = 0
	{
		integralRaw = 0;
	}

	integral = Ki * integralRaw;


	//Derivative
	derivative = Kd * (error - lastError);

	if (error == 0)
	{
		derivative = 0;
	}


	//Final Power
	liftPower -= proportion + integral + derivative;

	lastError = error;

	wait1Msec(8);
}

task moveLiftPot()
{
	while(true){
		if (liftBtn) {
			wait1Msec(250);
			potIndex = (potIndex == 0) ? 1: 0; //allows you to toggle the potIndex
		}
		PIDlift(potValues[potIndex]);
		sendLiftPower(liftPower);
	}
}
