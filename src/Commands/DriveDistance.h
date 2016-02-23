#ifndef DriveDistance_H
#define DriveDistance_H

#include "Commands/Command.h"
#include "WPILib.h"

class DriveDistance: public Command {
public:
	DriveDistance(float distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
