/*
 * XboxController.cpp
 *
 *  Created on: Jan 21, 2016
 *      Author: Steven
 */

#include "XboxController.h"
#include "Math.h"

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462379962749567351885752724891227938183011949129833673362440656643086021394946395224737190702179860943702770539217176293176752384674818467669405132000568127145263560827785771342757789609173637178721468440901224953430146549585371050792279689258923542019956112129021960864034418159813629774771309960518707211349999998372978049

XboxController::XboxController(int port) {
	portNumber = port;
	joystick = new Joystick(portNumber);
}

Vector* XboxController::GetVector(int xId, int yId, float xOffset, float yOffset) {
	float x = joystick->GetRawAxis(xId);
	float y = joystick->GetRawAxis(yId);

	float degrees = atan2(y,x);
	float magnitude = sqrt(x*x+y*y);

	return new Vector(magnitude, degrees);
}

Vector* XboxController::GetLeftVector() {
	return GetVector(LeftJoystickX, LeftJoystickY, LeftStickXOffset, LeftStickYOffset);
}

Vector* XboxController::GetRightVector() {
	return GetVector(RightJoystickX, RightJoystickY, RightStickXOffset, RightStickYOffset);
}

bool XboxController::GetButton(int buttonId) {
	if (buttonId == LeftTrigger){
		return GetTrigger(LeftTrigger, LeftTriggerOffset) >= LeftTriggerButtonThreshold;
	}

	else if (buttonId == RightTrigger){
		return GetTrigger(RightTrigger, RightTriggerOffset) >= RightTriggerButtonThreshold;
	}

	else {
		return joystick->GetRawButton(buttonId);
	}
}

bool XboxController::GetDPad(int DPadId) {
	DPadId = joystick->GetPOV();
	return DPadId;
}

float XboxController::GetTrigger (int TriggerId, int TriggerOffset) {
	float rawValue = joystick->GetRawAxis(TriggerId);
	return (rawValue - TriggerOffset) * 2;
}

void XboxController::Rumble(float value) {
	joystick->SetRumble(Joystick::RumbleType::kLeftRumble, value);
	joystick->SetRumble(Joystick::RumbleType::kRightRumble, value);
}


XboxController::~XboxController() {
	delete joystick;
}
