#include "DriveDistance.h"

#include "../Robot.h"

DriveDistance::DriveDistance(float distance): Command("DriveDistance") {
	Requires(Robot::drive_train.get());
	Robot::drive_train->SetSetpoint(distance);
}

// Called just before this Command runs the first time
void DriveDistance::Initialize() {
	Robot::drive_train->Reset();
	Robot::drive_train->Enable();
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistance::IsFinished() {
	Robot::drive_train->OnTarget();
}

// Called once after isFinished returns true
void DriveDistance::End() {
	Robot::drive_train->Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistance::Interrupted() {
	End();
}
