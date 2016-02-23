#include "OI.h"

OI::OI() {
	xbox_controller = std::shared_ptr<XBoxController>(new XBoxController(RobotMap::OPERATOR_CONTROLLER_PORT));
}
