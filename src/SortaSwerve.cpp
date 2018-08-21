#include <WPILib.h>
#include <Prefs.h>
#include <SortaSwerve.h>

SortaSwerve::SortaSwerve(void):
a_Joystick1(JOYSTICK_PORT_ONE),
FL_SwerveModule(FL_DRIVE_ONE_ID, FL_DRIVE_TWO_ID, FL_TURN_ID)
{
	SmartDashboard::init();
}

void SortaSwerve::RobotInit(void)
{
	FL_SwerveModule.ZeroEncoders();
}

void SortaSwerve::RobotPeriodic(void)
{
	SmartDashboard::PutString("Robot State: ", robotState);
}

void SortaSwerve::DisabledInit(void)
{

}

void SortaSwerve::DisabledPeriodic(void)
{
	robotState = "Disabled";
}

void SortaSwerve::TeleopInit(void)
{
	FL_SwerveModule.ZeroEncoders();
}

void SortaSwerve::TeleopPeriodic(void)
{
	robotState = "Teleoperated";

	FL_SwerveModule.UpdateRaw(a_Joystick1.GetRawAxis(1), a_Joystick1.GetRawAxis(0));

	float angleCounts;
	float distanceCounts;
	float calibratedAngle;
	float distanceIn;
	float distanceCm;
	float currentOutput1;
	float currentOutput2;
	float currentOutput3;
	float voltageOutput1;
	float voltageOutput2;
	float voltageOutput3;



	angleCounts = FL_SwerveModule.GetAngleRaw();
	distanceCounts = FL_SwerveModule.GetDistanceRaw();
	calibratedAngle = FL_SwerveModule.GetAngle();
	distanceIn = FL_SwerveModule.GetDistanceIn();
	distanceCm = FL_SwerveModule.GetDistanceCm();
	currentOutput1 = FL_SwerveModule.GetCurrentOP(FL_DRIVE_ONE_ID);
	currentOutput2 = FL_SwerveModule.GetCurrentOP(FL_DRIVE_TWO_ID);
	currentOutput3 = FL_SwerveModule.GetCurrentOP(FL_TURN_ID);
	voltageOutput1 = FL_SwerveModule.GetVoltageOP(FL_DRIVE_ONE_ID);
	voltageOutput2 = FL_SwerveModule.GetVoltageOP(FL_DRIVE_TWO_ID);
	voltageOutput3 = FL_SwerveModule.GetVoltageOP(FL_TURN_ID);


	SmartDashboard::PutNumber("Rotation Encoder: ", angleCounts);
	SmartDashboard::PutNumber("Distance Encoder: ", distanceCounts);
	SmartDashboard::PutNumber("Calculated Angle: ", calibratedAngle);
	SmartDashboard::PutNumber("Distance (In): ", distanceIn);
	SmartDashboard::PutNumber("Distance (Cm): ", distanceCm);
	SmartDashboard::PutNumber("Drive Current 1: ", currentOutput1);
	// SmartDashboard::PutNumber("Drive Current 2: ", currentOutput2);
	SmartDashboard::PutNumber("Turn Current: ", currentOutput3);
	SmartDashboard::PutNumber("Drive Voltage 1: ", voltageOutput1);
	// SmartDashboard::PutNumber("Drive Voltage 2: ", voltageOutput2);
	SmartDashboard::PutNumber("Turn Voltage: ", voltageOutput3);

}

void SortaSwerve::AutonomousInit(void)
{

}

void SortaSwerve::AutonomousPeriodic(void)
{
	robotState = "Autonomous";
}

void SortaSwerve::TestInit(void)
{

}

void SortaSwerve::TestPeriodic(void)
{
	robotState = "Test";
}

SortaSwerve::~SortaSwerve(void)
{

}

START_ROBOT_CLASS(SortaSwerve);
