#include "DriveTrain.h"

#include "../RobotMap.h"
#include "../Commands/TankDriveWithXBoxController.h"

DriveTrain::DriveTrain(): PIDSubsystem("DriveTrain", 1, 0, 0) {
	left_primary_motor = std::shared_ptr<CANTalon>(new CANTalon(RobotMap::LEFT_PRIMARY_MOTOR));
	left_secondary_motor = std::shared_ptr<Jaguar>(new Jaguar(RobotMap::LEFT_SECONDARY_MOTOR));

	right_primary_motor = std::shared_ptr<CANTalon>(new CANTalon(RobotMap::RIGHT_PRIMARY_MOTOR));
	right_secondary_motor = std::shared_ptr<Jaguar>(new Jaguar(RobotMap::RIGHT_SECONDARY_MOTOR));

	robot_drive = std::unique_ptr<RobotDrive>(
			new RobotDrive(left_primary_motor, left_secondary_motor,
							right_primary_motor, right_secondary_motor)
	);

	direction_modifier = -1;

	SetOutputRange(-1, 1);

	robot_drive->SetSafetyEnabled(true);
	robot_drive->SetExpiration(0.5);

	Reset();
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new TankDriveWithXBoxController());
}

void DriveTrain::Drive(float left, float right) {
	left *= direction_modifier;
	right *= direction_modifier;

	robot_drive->TankDrive(left, right, true);
}

void DriveTrain::UsePIDOutput(double output) {
	//robot_drive->TankDrive(output, output, false);
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

void DriveTrain::InvertDirection() {
	direction_modifier *= -1;
}

void DriveTrain::PrintInvertedStatus() {
	SmartDashboard::PutNumber("Direction", direction_modifier * -1);
}
