#ifndef RunShooter_H
#define RunShooter_H

#include "Commands/Command.h"
#include "WPILib.h"

#include "../Robot.h"

class RunShooter: public Command {
public:
	RunShooter(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float speed;
};

#endif
