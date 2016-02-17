#include "BallCollector.h"
#include "../RobotMap.h"

BallCollector::BallCollector(): Subsystem("BallCollector") {
	motor = new Talon(RobotMap::INTAKE_MOTOR);
}

void BallCollector::Start() {
	motor->Set(1);
}
void BallCollector::Stop() {
	motor->Set(0);
}
BallCollector::~BallCollector(){
	delete motor;
}
