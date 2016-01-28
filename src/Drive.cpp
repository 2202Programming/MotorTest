/*
 * Drive.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: Beast
 */

#include <Drive.h>

Drive::Drive() {
	motor = new Motor();
	xbox = NewXboxController::getInstance();

	leftSpeed = 0;
	rightSpeed = 0;
	forwardSpeed = 0;
	reverseSpeed = 0;
}

Drive::~Drive() {
}

void Drive::TeleopInit() {
	motor->setDrive(0.0, 0.0);
}
void Drive::TeleopPeriodic() {
	readXbox();
	updateMotors();
}
void Drive::readXbox() {
	if (xbox->getAxisLeftX() > 0) {  // To the right
		leftSpeed = xbox->getAxisLeftX();
		rightSpeed = -xbox->getAxisLeftX();
	} else if (xbox->getAxisLeftX() < 0) { //To the left
		leftSpeed = -xbox->getAxisLeftX();
		rightSpeed = xbox->getAxisLeftX();
	} else {
		leftSpeed = rightSpeed = 0;
	}

	forwardSpeed = xbox->getAxisLeftY();
}
void Drive::updateMotors() {
	motor->setDrive(forwardSpeed - leftSpeed, forwardSpeed - rightSpeed);
}

