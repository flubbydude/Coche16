#include "BallRetriever.h"

#include "../RobotMap.h"
#include "../Commands/RunBallRetriever.h"

BallRetriever::BallRetriever(): Subsystem("BallRetriever") {
	victor = std::unique_ptr<Victor>(new Victor(RobotMap::INTAKE_MOTOR));
}

void BallRetriever::InitDefaultCommand() {
	SetDefaultCommand(new RunBallRetriever(0));
}

void BallRetriever::Run(float speed) {
	victor->Set(speed, 0);
}
