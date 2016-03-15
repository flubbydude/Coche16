#include <Commands/DriveForTime.h>
#include "../Robot.h"

DriveForTime::DriveForTime(float target_time, float drive_speed): target_time(target_time), drive_speed(drive_speed) {
	Requires(Robot::drive_train.get());
	start_time = 0;
}

// Called just before this Command runs the first time
void DriveForTime::Initialize() {
	start_time = GetTime();
}

// Called repeatedly when this Command is scheduled to run
void DriveForTime::Execute() {
	if(fabs(GetTime() - start_time) <= target_time) {
		Robot::drive_train->Drive(drive_speed, drive_speed);
	} else {
		Robot::drive_train->Drive(0, 0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForTime::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveForTime::End() {
	Robot::drive_train->Drive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForTime::Interrupted() {
	End();
}
