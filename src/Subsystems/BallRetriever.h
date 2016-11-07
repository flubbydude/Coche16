#ifndef BallRetriever_H
#define BallRetriever_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class BallRetriever: public Subsystem {
private:
	std::unique_ptr<Talon> talon;

public:
	BallRetriever();
	void InitDefaultCommand();

	void Run(float speed);
};

#endif
