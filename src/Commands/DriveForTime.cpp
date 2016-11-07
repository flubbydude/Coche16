#include <Commands/DriveForTime.h>
#include "../Robot.h"

DriveForTime::DriveForTime(float target_time, float left_drive_speed, float right_drive_speed): target_time(target_time), left_drive_speed(left_drive_speed), right_drive_speed(right_drive_speed) {
	Requires(Robot::drive_train.get());
	start_time = 0;
}

// Called just before this Command runs the first time
void DriveForTime::Initialize() {
	start_time = GetTime();
}

// Called repeatedly when this Command is scheduled to run

 void DriveForTime::Execute() {

	if(GetTime() - start_time <= target_time) {
		Robot::drive_train->Drive(left_drive_speed, right_drive_speed);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForTime::IsFinished() {
	return GetTime() - start_time > target_time;
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
