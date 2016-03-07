#include "Robot.h"

#include "RobotMap.h"
#include "Commands/DriveDistance.h"

std::shared_ptr<DriveTrain> Robot::drive_train;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<BallRetriever> Robot::ball_retriever;

std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit() {
	drive_train.reset(new DriveTrain());
	shooter.reset(new Shooter());
	ball_retriever.reset(new BallRetriever());

	oi.reset(new OI());

	last_inverted_time = GetTime();
}

void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	// TODO Auto command
	//autonomousCommand.reset((Command *)chooser->GetSelected());
	//autonomousCommand.reset(new DriveDistance(100));

	//drive_train->left_primary_motor->SetControlMode(CANTalon::ControlMode::kSpeed);
	//drive_train->right_primary_motor->SetControlMode(CANTalon::ControlMode::kSpeed);

	if (autonomousCommand != NULL) autonomousCommand->Start();


	drive_train->left_primary_motor->SetPosition(0);
	drive_train->right_primary_motor->SetPosition(0);
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();

	if(drive_train->left_primary_motor->GetPosition() < 50) {
		drive_train->Drive(0.3, 0.3);
	}


	SmartDashboard::PutNumber("LPost", drive_train->left_primary_motor->GetPosition());
	SmartDashboard::PutNumber("LVel", drive_train->left_primary_motor->GetEncVel());
}

void Robot::TeleopInit() {
	if (autonomousCommand != NULL) autonomousCommand->Cancel();

	drive_train->Reset();
	oi->xbox_controller->Calibrate();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

	if(oi->xbox_controller->GetButton(XBoxController::BUTTON_START)) {
		oi->xbox_controller->Calibrate();
	}

	drive_train->PrintInvertedStatus();
	if(GetTime() - last_inverted_time >= 0.5 && oi->xbox_controller->GetButton(XBoxController::BUTTON_A)) {
		drive_train->InvertDirection();
	}

	//SmartDashboard::PutNumber("LCount", drive_train->left_primary_motor->GetPosition());
	//SmartDashboard::PutNumber("RCount", drive_train->right_primary_motor->GetPosition());

}

void Robot::TestPeriodic() {
	LiveWindow::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot)

