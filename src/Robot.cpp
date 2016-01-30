#include "WPILib.h"
#include "IControl.h"
#include "NewXboxController.h"
#include "Drive.h"
#include "Motor.h"

#define CONTROLLERS 3

class Robot: public IterativeRobot {
private:
	LiveWindow *lw = LiveWindow::GetInstance();
	//IControl *controllers[CONTROLLERS];

	NewXboxController *xbox;
	/*Spark *leftFront;
	Spark *leftBack;
	Spark *rightFront; // Negative Input
	Spark *rightBack; //Negative Input */

	Motor *m;
	Drive *d;

	void RobotInit() {
		xbox = NewXboxController::getInstance();
		/*leftFront = new Spark(1);
		leftBack = new Spark(2);
		rightFront = new Spark(3);
		rightBack = new Spark(4);*/

		d = new Drive();
		m = d->motor;
	}

	void AutonomousInit() {
	}

	void AutonomousPeriodic() {
	}

	void TeleopInit() {
		/*leftFront->Set(0);
		leftBack->Set(0);
		rightFront->Set(0);
		rightBack->Set(0); */

		d->TeleopInit();
		m->TeleopInit();
	}

	void TeleopPeriodic() {
		xbox->update();

		/*if (xbox->isXHeld()) {
			leftFront->Set(0.2);
			leftBack->Set(0.2);
			rightFront->Set(-0.2);
			rightBack->Set(-0.2);
		} else if (xbox->isBHeld()) {
			leftFront->Set(-0.2);
			leftBack->Set(-0.2);
			rightFront->Set(0.2);
			rightBack->Set(0.2);
		}*/

		/*leftFront->Set(0.2);
		leftBack->Set(0.2);
		rightFront->Set(-0.2);
		rightBack->Set(-0.2);
	*/
		SmartDashboard::PutNumber("Xleft", xbox->getAxisLeftX());
		SmartDashboard::PutNumber("Yleft", xbox->getAxisLeftY());
		m->leftSpeed = .5;
		m->rightSpeed = .5;
		d->TeleopPeriodic();
		m->TeleopPeriodic();
	}

	void TestPeriodic() {
		lw->Run();
	}
}
;

START_ROBOT_CLASS(Robot)
