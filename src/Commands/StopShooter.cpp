#include "StopShooter.h"

#include "../Robot.h"

StopShooter::StopShooter(): Command("StopShooter") {
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void StopShooter::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void StopShooter::Execute() {
	End();
}

// Make this return true when this Command no longer needs to run execute()
bool StopShooter::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void StopShooter::End() {
	Robot::shooter->Run(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopShooter::Interrupted() {
	End();
}
