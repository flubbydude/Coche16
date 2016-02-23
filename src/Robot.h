#ifndef ROBOT_H
#define ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"

#include "OI.h"

#include "Subsystems/DriveTrain.h"

class Robot: public IterativeRobot {
public:
	static std::shared_ptr<DriveTrain> drive_train;

	static std::unique_ptr<OI> oi;

private:
	std::unique_ptr<Command> autonomousCommand;

	void RobotInit();
	void DisabledInit();
	void DisabledPeriodic();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};

#endif
