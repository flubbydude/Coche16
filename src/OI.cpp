#include "OI.h"

#include "RobotMap.h"

#include "Commands/RunShooter.h"
#include "Commands/RunBallRetriever.h"
#include "Commands/TankDriveWithXBoxController.h"

OI::OI() {
	xbox_controller = std::shared_ptr<XBoxController>(new XBoxController(RobotMap::OPERATOR_CONTROLLER_PORT));

	xbox_controller->GetJoystickButton(XBoxController::BUTTON_RIGHT_BUMPER)->WhenPressed(new RunShooter(1));
	xbox_controller->GetTriggerJoystickButton(XBoxController::AXIS_RIGHT_TRIGGER_ID, XBoxController::RIGHT_TRIGGER_BUTTON_THRESHOLD)->WhenPressed(new RunShooter(-1));

	xbox_controller->GetJoystickButton(XBoxController::BUTTON_LEFT_BUMPER)->WhenPressed(new RunBallRetriever(1));
	xbox_controller->GetTriggerJoystickButton(XBoxController::AXIS_LEFT_TRIGGER_ID, XBoxController::LEFT_TRIGGER_BUTTON_THRESHOLD)->WhenPressed(new RunBallRetriever(-1));
}
