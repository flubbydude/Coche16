#include "AutonomousCommandGroup.h"
#include "../Commands/DriveForTime.h"
#include "../Commands/DriveUntilInterrupt.h"

AutonomousCommandGroup::AutonomousCommandGroup() {
	//AddSequential(new DriveForTime(2, 0.5, 0.5));
	//AddSequential(new DriveForTime(0.1, 0, 0));
	//AddSequential(new DriveForTime(3, -0.5, -0.5));
	AddSequential(new DriveForTime(1, 1.0, -1.0));//turn right some amount
	//AddSequential(new DriveForTime(1, -1.0, 1.0));//turn left some amount
	AddSequential(new DriveUntilInterrupt(0));
}
