#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "XboxController.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/BallCollector.h"

class Robot: public IterativeRobot {

private:
	std::unique_ptr<Command> autonomousCommand;
	SendableChooser *chooser;
	std::unique_ptr<XboxController> controller;
	std::unique_ptr<RobotDrive> robot_drive;
	std::unique_ptr<Shooter> shooter;
	std::unique_ptr<BallCollector> picker_upper;

	void RobotInit() {
		CommandBase::init();
		chooser = new SendableChooser();
		chooser->AddDefault("Default Auto", new ExampleCommand());
		//chooser->AddObject("My Auto", new MyAutoCommand());
		SmartDashboard::PutData("Auto Modes", chooser);
		controller = std::unique_ptr<XboxController>(new XboxController(0));
		robot_drive = std::unique_ptr<RobotDrive> (new RobotDrive(1,2,3,4));
		shooter = std::unique_ptr<Shooter> (new Shooter());
		picker_upper = std::unique_ptr<BallCollector> (new BallCollector());
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit() {
	}

	void DisabledPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() {
		/* std::string autoSelected = SmartDashboard::GetString("Auto Selector", "Default");
		if(autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		} else {
			autonomousCommand.reset(new ExampleCommand());
		} */

		autonomousCommand.reset((Command *)chooser->GetSelected());

		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();

		std::unique_ptr<Vector> left_stick_vector = std::unique_ptr<Vector>(controller->GetLeftVector());
		std::unique_ptr<Vector> right_stick_vector = std::unique_ptr<Vector>(controller->GetRightVector());

		robot_drive->TankDrive(left_stick_vector->magnitude, right_stick_vector->magnitude, false);

		if (controller->GetTrigger(controller->RightTrigger,controller->RightTriggerOffset) >= 0.5){
			shooter->run_shooter();
		}else{
			shooter->stop_shooter();
		}

		if (controller->GetTrigger(controller->LeftTrigger,controller->LeftTriggerOffset) >= 0.5){
			picker_upper->Start();
		}else{
			picker_upper->Stop();
		}
	}

	void TestPeriodic() {
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)

