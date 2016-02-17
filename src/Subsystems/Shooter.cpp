#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter(): Subsystem("Shooter") {
	lMotor = new Talon(RobotMap::LEFT_SHOOTER_MOTOR);
	rMotor = new Talon(RobotMap::RIGHT_SHOOTER_MOTOR);
}

void Shooter::InitDefaultCommand() {

}

void Shooter::run_shooter() {
	//spins up the motors to shoot the ball
	lMotor->SetSpeed(1.0);
	rMotor->SetSpeed(1.0);
	//will need to stop the motors a few seconds after they're turned on
}

void Shooter::stop_shooter() {
	lMotor->SetSpeed(0.0);
	rMotor->SetSpeed(0.0);
}

Shooter::~Shooter() {
	delete lMotor;
	delete rMotor;
}
