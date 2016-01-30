/*
 * Motor.h
 *
 *  Created on: Jan 27, 2016
 *      Author: Beast
 */
#pragma once

#include "IControl.h"
#include "WPILib.h"


class Motor {
public:
	Motor();
	virtual ~Motor();
	void TeleopInit();
	void TeleopPeriodic();
	void setDrive(float speedL, float speedR);
	float leftSpeed;
	float rightSpeed;

protected:
	Spark *frontLeft;
	Spark *frontRight;
	Spark *backLeft;
	Spark *backRight;


};

