#include "Shooter.h"

#include "../RobotMap.h"
#include "../Commands/StopShooter.h"

Shooter::Shooter(): Subsystem("Shooter") {
	left_talon = std::unique_ptr<Talon>(new Talon(RobotMap::LEFT_SHOOTER_MOTOR));
	right_talon = std::unique_ptr<Talon>(new Talon(RobotMap::RIGHT_SHOOTER_MOTOR));
}

void Shooter::InitDefaultCommand() {
	SetDefaultCommand(new StopShooter());
}

void Shooter::Run(float speed) {
	left_talon->Set(speed, 0);
	right_talon->Set(speed * -1, 0);
}
