#ifndef TankDriveWithXBoxController_H
#define TankDriveWithXBoxController_H

#include "WPILib.h"
#include "Commands/Command.h"

#include "../Models/Vector.h"

class TankDriveWithXBoxController: public Command
{
public:
	TankDriveWithXBoxController();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
