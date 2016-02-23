#include "DriveTrain.h"

#include "../RobotMap.h"
#include "../Commands/TankDriveWithXBoxController.h"

DriveTrain::DriveTrain(): PIDSubsystem("DriveTrain", 1, 0, 0) {
	robot_drive = std::unique_ptr<RobotDrive>(
			new RobotDrive(RobotMap::LEFT_PRIMARY_MOTOR, RobotMap::LEFT_SECONDARY_MOTOR,
							RobotMap::RIGHT_PRIMARY_MOTOR, RobotMap::RIGHT_SECONDARY_MOTOR)
	);

	left_primary_motor = std::unique_ptr<CANTalon>(new CANTalon(RobotMap::LEFT_PRIMARY_MOTOR));
	right_primary_motor = std::unique_ptr<CANTalon>(new CANTalon(RobotMap::RIGHT_PRIMARY_MOTOR));

	SetOutputRange(-1, 1);
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new TankDriveWithXBoxController());
}

void DriveTrain::Drive(float left, float right) {
	robot_drive->TankDrive(left, right, true);
}

void DriveTrain::UsePIDOutput(double output) {
	robot_drive->TankDrive(output, output, false);
}

double DriveTrain::ReturnPIDInput() {
	return (left_primary_motor->GetPosition() + right_primary_motor->GetPosition()) / 2;
}

void DriveTrain::Reset() {
	Drive(0, 0);

	left_primary_motor->SetPosition(0);
	right_primary_motor->SetPosition(0);

	Disable();
	SetSetpoint(0);
}
