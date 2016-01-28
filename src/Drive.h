/*
 * Drive.h
 *
 *  Created on: Jan 27, 2016
 *      Author: Beast
 */

#include "WPILib.h"
#include "IControl.h"
#include "Motor.h"
#include "NewXboxController.h"

#ifndef SRC_DRIVE_H_
#define SRC_DRIVE_H_

class Drive: public IControl {
public:
	Drive();
	virtual ~Drive();

	void TeleopInit();
	void TeleopPeriodic();

	void readXbox();
	void updateMotors();

	Motor *motor;
	NewXboxController *xbox;

	double leftSpeed;
	double rightSpeed;
	double forwardSpeed;
};

#endif /* SRC_DRIVE_H_ */
