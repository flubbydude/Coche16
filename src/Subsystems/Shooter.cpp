#include "Shooter.h"

#include "../RobotMap.h"
#include "../Commands/RunShooter.h"

Shooter::Shooter(): Subsystem("Shooter") {
	left_victor = std::unique_ptr<Victor>(new Victor(RobotMap::LEFT_SHOOTER_MOTOR));
	right_victor = std::unique_ptr<Victor>(new Victor(RobotMap::RIGHT_SHOOTER_MOTOR));
}

void Shooter::InitDefaultCommand() {
	SetDefaultCommand(new RunShooter(0));
}

void Shooter::Run(float speed) {
	left_victor->Set(speed, 0);
	right_victor->Set(speed * -1, 0);
}
