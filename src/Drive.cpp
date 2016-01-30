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

	leftSpeed = 0.0;
	rightSpeed = 0.0;
}

Drive::~Drive() {
}

void Drive::TeleopInit() {
	motor->setDrive(0.0, 0.0);
}
void Drive::TeleopPeriodic() {
	readXboxArcadeD();
	updateMotors();
}
void Drive::readXboxTank() {
	leftSpeed = xbox->getAxisLeftY();
	rightSpeed = xbox->getAxisRightY();
}

void Drive::readXboxArcadeT() {
	float x = xbox->getAxisLeftX();
	float y = xbox->getAxisLeftY();

	SmartDashboard::PutNumber("X Value", x);
	SmartDashboard::PutNumber("Y Value", y);

	x *= .5;

	leftSpeed = y;
	rightSpeed = y;

	leftSpeed -= x;
	rightSpeed += x;
}

void Drive::readXboxArcadeD() {
	float x = xbox->getAxisLeftX();
	float y = xbox->getAxisLeftY();

	SmartDashboard::PutNumber("X Value", x);
	SmartDashboard::PutNumber("Y Value", y);

	if (y > 0) y *= y;
	else y *= -y;

	if (x > 0) x *= x;
	else x*= -x;

	//leftSpeed = y - x;
	//rightSpeed = y + x;

	leftSpeed = acceleration(y - x, leftSpeed);
	rightSpeed = acceleration(y + x, rightSpeed);

	SmartDashboard::PutNumber("XOut Value", rightSpeed);
	SmartDashboard::PutNumber("YOut Value", leftSpeed);
}

float Drive::acceleration(float newS, float oldS) {
	if (fabs(newS - oldS) > 0.2) {
		if (oldS > newS)return oldS - 0.2;
		else return oldS + 0.2;
	}

	return newS;
}

void Drive::updateMotors() {
	motor->setDrive(leftSpeed, rightSpeed);
}

