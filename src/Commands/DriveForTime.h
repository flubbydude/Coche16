#ifndef DriveFortime_H
#define DriveFortime_H

#include "Commands/Command.h"
#include "WPILib.h"

class DriveForTime: public Command {
public:
	DriveForTime(float target_time, float drive_speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float target_time;
	float drive_speed;
	float start_time;
};

#endif
