#include "Robot.h"

std::shared_ptr<DriveTrain> Robot::drive_train;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<BallRetriever> Robot::ball_retriever;

std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit() {
	drive_train.reset(new DriveTrain());
	shooter.reset(new Shooter());
	ball_retriever.reset(new BallRetriever());

	oi.reset(new OI());
}

void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	// TODO Auto command
	//autonomousCommand.reset((Command *)chooser->GetSelected());

	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	LiveWindow::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot)

