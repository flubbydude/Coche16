#include "RunBallRetriever.h"

RunBallRetriever::RunBallRetriever(float speed): Command("RunBallRetriever"), speed(speed){
	Requires(Robot::ball_retriever.get());
}

// Called just before this Command runs the first time
void RunBallRetriever::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void RunBallRetriever::Execute() {
	Robot::ball_retriever->Run(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool RunBallRetriever::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RunBallRetriever::End() {
	Robot::ball_retriever->Run(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunBallRetriever::Interrupted() {
	End();
}
