#ifndef DriveFortime_H
#define DriveFortime_H

#include "Commands/Command.h"
#include "WPILib.h"

class DriveForTime: public Command {
public:
	DriveForTime(float target_time, float left_drive_speed, float right_drive_speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double target_time;
	float left_drive_speed;
	float right_drive_speed;
	double start_time;
};

#endif
