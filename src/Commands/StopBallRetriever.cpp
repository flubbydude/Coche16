#include "StopBallRetriever.h"

#include "../Robot.h"

StopBallRetriever::StopBallRetriever(): Command("StopBallRetriever") {
	Requires(Robot::ball_retriever.get());
}

// Called just before this Command runs the first time
void StopBallRetriever::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void StopBallRetriever::Execute() {
	End();
}

// Make this return true when this Command no longer needs to run execute()
bool StopBallRetriever::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void StopBallRetriever::End() {
	Robot::ball_retriever->Run(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopBallRetriever::Interrupted() {
	End();
}
