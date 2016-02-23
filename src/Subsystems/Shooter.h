#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shooter: public Subsystem {
public:
	Shooter();
	void InitDefaultCommand();

	void Run(float speed);

private:
	std::unique_ptr<Talon> left_talon;
	std::unique_ptr<Talon> right_talon;
};

#endif
