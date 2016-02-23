#include "RunShooter.h"

#include "../Robot.h"

RunShooter::RunShooter(float speed): Command("RunShooter"), speed(speed) {
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void RunShooter::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void RunShooter::Execute() {
	Robot::shooter->Run(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool RunShooter::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RunShooter::End() {
	Robot::shooter->Run(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunShooter::Interrupted() {
	End();
}
