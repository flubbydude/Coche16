#include "DriveTrain.h"

DriveTrain::DriveTrain(): Subsystem("DriveTrain") {
	robot_drive = std::unique_ptr<RobotDrive>(
			new RobotDrive(RobotMap::LEFT_PRIMARY_MOTOR, RobotMap::LEFT_SECONDARY_MOTOR,
							RobotMap::RIGHT_PRIMARY_MOTOR, RobotMap::RIGHT_SECONDARY_MOTOR)
	);
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void DriveTrain::Drive(float left, float right) {
	robot_drive->TankDrive(left, right);
}


