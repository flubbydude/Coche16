#include <Subsystems/Drivetrain.h>
#include "WPILib.h"

#include "XboxController.h"

#include "Subsystems/Shooter.h"
#include "Subsystems/BallCollector.h"

class Robot: public IterativeRobot {
private:
	// Input devices
	std::unique_ptr<XboxController> controller;

	// Subsystems
	std::unique_ptr<Drivetrain> drive_train;
	std::unique_ptr<Shooter> shooter;
	std::unique_ptr<BallCollector> ball_collector;

	void RobotInit() {
		// Input devices
		controller = std::unique_ptr<XboxController>(new XboxController(0));

		// Subsystems
		drive_train = std::unique_ptr<Drivetrain> (new Drivetrain());
		shooter = std::unique_ptr<Shooter> (new Shooter());
		ball_collector = std::unique_ptr<BallCollector> (new BallCollector());
	}

	void DisabledInit() {
	}

	void DisabledPeriodic() {

	}

	void AutonomousInit() {

	}

	void AutonomousPeriodic() {

	}

	void TeleopInit() {

	}

	void TeleopPeriodic() {
		// Chases drive
		std::unique_ptr<Vector> left_stick_vector = std::unique_ptr<Vector>(controller->GetLeftVector());
		std::unique_ptr<Vector> right_stick_vector = std::unique_ptr<Vector>(controller->GetRightVector());

		drive_train->Drive(left_stick_vector->magnitude, right_stick_vector->magnitude);

		// Shooter control
		if (controller->GetTrigger(controller->RightTrigger,controller->RightTriggerOffset) >= 0.5) {
			shooter->run_shooter();
		} else {
			shooter->stop_shooter();
		}

		// Ball Collector control
		if (controller->GetTrigger(controller->LeftTrigger,controller->LeftTriggerOffset) >= 0.5) {
			ball_collector->Start();
		} else {
			ball_collector->Stop();
		}
	}

	void TestPeriodic() {

	}
};

START_ROBOT_CLASS(Robot)

