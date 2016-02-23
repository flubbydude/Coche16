#ifndef StopBallRetriever_H
#define StopBallRetriever_H

#include "Commands/Command.h"
#include "WPILib.h"

class StopBallRetriever: public Command {
public:
	StopBallRetriever();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
