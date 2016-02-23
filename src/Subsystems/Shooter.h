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
	std::unique_ptr<Victor> left_victor;
	std::unique_ptr<Victor> right_victor;
};

#endif
