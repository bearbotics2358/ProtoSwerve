#include <WPILib.h>
#include <Prefs.h>
#include <SortaSwerve.h>

SortaSwerve::SortaSwerve(void):
a_Joystick1(JOYSTICK_PORT_ONE),
FL_SwerveModule(FL_DRIVE_ONE_ID, FL_DRIVE_TWO_ID, FL_TURN_ID),
FR_SwerveModule(FR_DRIVE_ONE_ID, FR_DRIVE_TWO_ID, FR_TURN_ID),
a_SwerveDrive()
{
	cruiseControl = false;
	crabToggle = false;
	driveSpeed = 0;
	rotationSpeed = 0;
	SmartDashboard::init();
}

void SortaSwerve::RobotInit(void)
{
	FL_SwerveModule.ZeroEncoders();
}

void SortaSwerve::RobotPeriodic(void)
{

}

void SortaSwerve::DisabledInit(void)
{
	robotState = "Disabled";
}

void SortaSwerve::DisabledPeriodic(void)
{

}

void SortaSwerve::TeleopInit(void)
{

}

void SortaSwerve::TeleopPeriodic(void)
{
	robotState = "Teleoperated";

	if(a_Joystick1.GetRawButton(2)) // Enable Cruise Control
	{
		// cruiseControl = true;
		driveSpeed = a_Joystick1.GetRawAxis(1);
		rotationSpeed = a_Joystick1.GetRawAxis(0);
	}

	if(a_Joystick1.GetRawButton(3)) // Disable Cruise Control
	{
		// cruiseControl = false;
	}

	if(a_Joystick1.GetRawButton(8))
	{
		crabToggle = true;
	}

	if(a_Joystick1.GetRawButton(9))
	{
		crabToggle = false;
	}

	if(cruiseControl)
	{
		// FL_SwerveModule.UpdateRaw(driveSpeed, rotationSpeed);
	}
	else
	{
		if(crabToggle)
		{
			a_SwerveDrive.CrabDrive(a_Joystick1.GetRawAxis(0), a_Joystick1.GetRawAxis(1), a_Joystick1.GetRawAxis(2));
		}
		else
		{
			FL_SwerveModule.UpdateRaw(a_Joystick1.GetRawAxis(1), a_Joystick1.GetRawAxis(0));
		}
	}

	if(a_Joystick1.GetRawButton(11))
	{
		FL_SwerveModule.UpdateAngle(45);
	}
	else if(a_Joystick1.GetRawButton(10))
	{
		FL_SwerveModule.UpdateAngle(137);
	}
	else if(a_Joystick1.GetRawButton(7))
	{
		FL_SwerveModule.UpdateAngle(-137);
	}
	else if(a_Joystick1.GetRawButton(6))
	{
		FL_SwerveModule.UpdateAngle(-45);
	}

	float angleCounts;
	float distanceCounts;
	float calibratedAngle;
	float distanceIn;
	float distanceCm;
	// float currentOutput1;
	// float currentOutput2;
	// float currentOutput3;
	// float voltageOutput1;
	// float voltageOutput2;
	// float voltageOutput3;



	angleCounts = FL_SwerveModule.GetAngleRaw();
	distanceCounts = FL_SwerveModule.GetDistanceRaw();
	calibratedAngle = FL_SwerveModule.GetAngle();
	distanceIn = FL_SwerveModule.GetDistanceIn();
	distanceCm = FL_SwerveModule.GetDistanceCm();
	// currentOutput1 = FL_SwerveModule.GetCurrentOP(FL_DRIVE_ONE_ID);
	// currentOutput2 = FL_SwerveModule.GetCurrentOP(FL_DRIVE_TWO_ID);
	// currentOutput3 = FL_SwerveModule.GetCurrentOP(FL_TURN_ID);
	// voltageOutput1 = FL_SwerveModule.GetVoltageOP(FL_DRIVE_ONE_ID);
	// voltageOutput2 = FL_SwerveModule.GetVoltageOP(FL_DRIVE_TWO_ID);
	// voltageOutput3 = FL_SwerveModule.GetVoltageOP(FL_TURN_ID);


	SmartDashboard::PutNumber("Rotation Encoder: ", angleCounts);
	SmartDashboard::PutNumber("Distance Encoder: ", distanceCounts);
	SmartDashboard::PutNumber("Calculated Angle: ", calibratedAngle);
	SmartDashboard::PutNumber("Distance (In): ", distanceIn);
	SmartDashboard::PutNumber("Distance (Cm): ", distanceCm);
	// SmartDashboard::PutNumber("Drive Current 1: ", currentOutput1);
	// SmartDashboard::PutNumber("Drive Current 2: ", currentOutput2);
	// SmartDashboard::PutNumber("Turn Current: ", currentOutput3);
	// SmartDashboard::PutNumber("Drive Voltage 1: ", voltageOutput1);
	// SmartDashboard::PutNumber("Drive Voltage 2: ", voltageOutput2);
	// SmartDashboard::PutNumber("Turn Voltage: ", voltageOutput3);
	SmartDashboard::PutBoolean("Cruise Control", cruiseControl);
}

void SortaSwerve::AutonomousInit(void)
{
	robotState = "Autonomous";
}

void SortaSwerve::AutonomousPeriodic(void)
{

}

void SortaSwerve::TestInit(void)
{
	robotState = "Test";

}

void SortaSwerve::TestPeriodic(void)
{

	a_SwerveDrive.CrabDrivePID(a_Joystick1.GetRawAxis(0), a_Joystick1.GetRawAxis(1), a_Joystick1.GetRawAxis(2));
	/*if(a_Joystick1.GetRawButton(6))
	{
		FL_SwerveModule.UpdateAnglePID(90);
	}
	else if(a_Joystick1.GetRawButton(7))
	{
		FL_SwerveModule.UpdateAnglePID(0);
	}
	else
	{
		FL_SwerveModule.UpdateAnglePID(270);
	}
	*/
	double calibratedAngle = FR_SwerveModule.GetAngle() + 180;
	SmartDashboard::PutNumber("Calculated Angle: ", calibratedAngle);

}

SortaSwerve::~SortaSwerve(void)
{

}

START_ROBOT_CLASS(SortaSwerve);
