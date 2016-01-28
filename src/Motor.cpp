/*
 * Motor.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: Beast
 */

#include <Motor.h>

#define MOTORFL 0
#define MOTORFR 2
#define MOTORBL 1
#define MOTORBR 3

Motor::Motor() {
	frontLeft = new Spark(MOTORFL);
	frontRight = new Spark(MOTORFR);
	backLeft = new Spark(MOTORBL);
	backRight = new Spark(MOTORBR);

	writeSpeedFL = 0.1;
	writeSpeedFR = 0.1;
	writeSpeedBL = 0.1;
	writeSpeedBR = 0.1;
}

Motor::~Motor() {
}

void Motor::TeleopInit() {
	frontLeft->Set(0);
	frontRight->Set(0);
	backLeft->Set(0);
	backRight->Set(0);
}

void Motor::TeleopPeriodic() {
	frontLeft->Set(writeSpeedFL);
	frontRight->Set(writeSpeedFR);
	backLeft->Set(writeSpeedBL);
	backRight->Set(writeSpeedBR);
}

void Motor::setDrive(double speedL, double speedR) {
	writeSpeedFL = speedL;
	writeSpeedFR = speedR;
	writeSpeedBL = speedL;
	writeSpeedBR = speedR;
}

