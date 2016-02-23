#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public PIDSubsystem {
public:
	DriveTrain();
	void InitDefaultCommand();

	void Drive(float left, float right);
	void UsePIDOutput(double output);
	double ReturnPIDInput();

	void Reset();

private:
	std::unique_ptr<RobotDrive> robot_drive;

	std::unique_ptr<CANTalon> left_primary_motor;
	std::unique_ptr<CANTalon> right_primary_motor;
};

#endif
