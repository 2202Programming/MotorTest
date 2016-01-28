/*
 * Motor.h
 *
 *  Created on: Jan 27, 2016
 *      Author: Beast
 */
#pragma once

#include "IControl.h"
#include "WPILib.h"


class Motor: public IControl {
public:
	Motor();
	virtual ~Motor();
	void TeleopInit();
	void TeleopPeriodic();
	void setDrive(double speedL,double speedR);

protected:
	Spark *frontLeft;
	Spark *frontRight;
	Spark *backLeft;
	Spark *backRight;

	double writeSpeedFL;
	double writeSpeedFR;
	double writeSpeedBL;
	double writeSpeedBR;
};

