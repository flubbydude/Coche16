#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include "RobotMap.h"
#include "Models/XBoxController.h"

#include "Commands/RunShooter.h"
#include "Commands/RunBallRetriever.h"
#include "Commands/TankDriveWithXBoxController.h"

class OI {
public:
	std::shared_ptr<XBoxController> xbox_controller;

	OI();
};

#endif
