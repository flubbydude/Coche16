#include "BallRetriever.h"

#include "../RobotMap.h"
#include "../Commands/StopBallRetriever.h"

BallRetriever::BallRetriever(): Subsystem("BallRetriever") {
	talon = std::unique_ptr<Talon>(new Talon(RobotMap::INTAKE_MOTOR));
}

void BallRetriever::InitDefaultCommand() {
	SetDefaultCommand(new StopBallRetriever());
}

void BallRetriever::Run(float speed) {
	talon->Set(speed, 0);
}
