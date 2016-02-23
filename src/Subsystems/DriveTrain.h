#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem {
private:
	std::unique_ptr<RobotDrive> robot_drive;

public:
	DriveTrain();
	void InitDefaultCommand();

	void Drive(float left, float right);
};

#endif
