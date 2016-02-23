#ifndef RunBallRetriever_H
#define RunBallRetriever_H

#include "Commands/Command.h"
#include "WPILib.h"

#include "../Robot.h"

class RunBallRetriever: public Command {
public:
	RunBallRetriever(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float speed;
};

#endif
