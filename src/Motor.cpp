/*
 * Motor.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: Beast
 */

#include <Motor.h>

#define MOTORFL 1
#define MOTORBL 2
#define MOTORFR 3
#define MOTORBR 4

Motor::Motor() {
	frontLeft = new Spark(MOTORFL);
	frontRight = new Spark(MOTORFR);
	backLeft = new Spark(MOTORBL);
	backRight = new Spark(MOTORBR);

	rightSpeed = 0.0;
	leftSpeed = 0.0;
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
	/*frontLeft->Set(0.2);
	backLeft->Set(0.2);
	frontRight->Set(-0.2);
	backRight->Set(-0.2); */
	SmartDashboard::PutNumber("Left Speed", leftSpeed);
	SmartDashboard::PutNumber("Right Speed", rightSpeed);
	frontLeft->Set(leftSpeed);
	backLeft->Set(leftSpeed);
	frontRight->Set(rightSpeed);
	backRight->Set(rightSpeed);
}

void Motor::setDrive(float speedL, float speedR) {
	SmartDashboard::PutBoolean("Set Drive run", true);
	leftSpeed = speedL;
	rightSpeed = -speedR;
}

