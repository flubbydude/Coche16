																	#include <Subsystems/Drivetrain.h>
#include "WPILib.h"

#include "XboxController.h"

#include "Subsystems/Shooter.h"
#include "Subsystems/BallCollector.h"
#include "DriveMode.h"

class Robot: public IterativeRobot {
private:
	// Input devices
	std::unique_ptr<XboxController> controller;

	// Subsystems
	std::unique_ptr<Drivetrain> drive_train;
	std::unique_ptr<Shooter> shooter;
	std::unique_ptr<BallCollector> ball_collector;

	DriveMode drive_mode;
	bool right_bumper_pressed;

	void RobotInit() {
		// Input devices
		controller = std::unique_ptr<XboxController>(new XboxController(0));

		// Subsystems
		drive_train = std::unique_ptr<Drivetrain> (new Drivetrain());
		shooter = std::unique_ptr<Shooter> (new Shooter());
		ball_collector = std::unique_ptr<BallCollector> (new BallCollector());

		drive_mode = DriveMode::TANK;
		right_bumper_pressed = false;
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

		int left_direction_mod = -1;
		int right_direction_mod = -1;

		if(left_stick_vector->magnitude >= M_PI && left_stick_vector->magnitude <= 2*M_PI) {
			left_direction_mod *= -1;
		}

		if(right_stick_vector->magnitude >= M_PI && right_stick_vector->magnitude <= 2*M_PI) {
			right_direction_mod *= -1;
		}


		if(controller->GetButton(controller->ButtonRB)) {
			if(drive_mode == DriveMode::TANK && !right_bumper_pressed) {
				drive_mode = DriveMode::ARCADE;
			} else if(!right_bumper_pressed) {
				drive_mode = DriveMode::TANK;
			}

			right_bumper_pressed = true;
		} else {
			right_bumper_pressed = false;
		}

		switch(drive_mode) {
			case DriveMode::TANK:
				drive_train->TankDrive(left_stick_vector->magnitude * left_direction_mod,
									right_stick_vector->magnitude * right_direction_mod);

				SmartDashboard::PutString("Drive Mode", "Tank");
			case DriveMode::ARCADE:
				float left_stick_turn = left_stick_vector->angle - (M_PI / 2);
				float right_stick_turn = right_stick_vector->angle - (M_PI / 2);
				drive_train->ArcadeDrive(left_stick_vector->magnitude * left_direction_mod, left_stick_turn + right_stick_turn);

				SmartDashboard::PutString("Drive Mode", "Arcade");
		}

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

