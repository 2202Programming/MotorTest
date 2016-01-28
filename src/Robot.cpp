#include "WPILib.h"
#include "IControl.h"
#include "NewXboxController.h"
#include "Drive.h"
#include "Motor.h"

#define CONTROLLERS 3

class Robot: public IterativeRobot {
private:
	LiveWindow *lw = LiveWindow::GetInstance();
	IControl *controllers[CONTROLLERS];

	void RobotInit() {
		for (int i = 0; i < CONTROLLERS; i++) {
			controllers[i] = NULL;
		}

		controllers[0] = NewXboxController::getInstance();
		controllers[1] = new Drive();
		controllers[2] = new Motor();
	}

	void AutonomousInit() {
	}

	void AutonomousPeriodic() {
	}

	void TeleopInit() {
		for (int i = 0; i < CONTROLLERS; i ++) {
			controllers[i]->TeleopInit();
		}
	}

	void TeleopPeriodic() {
		for (int i = 0; i < CONTROLLERS; i++) {
			controllers[i]->TeleopPeriodic();
		}
	}

	void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
