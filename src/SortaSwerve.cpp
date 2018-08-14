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

	angleCounts = FL_SwerveModule.GetAngleRaw();
	distanceCounts = FL_SwerveModule.GetDistanceRaw();
	calibratedAngle = FL_SwerveModule.GetAngle();

	SmartDashboard::PutNumber("Rotation Encoder: ", angleCounts);
	SmartDashboard::PutNumber("Distance Encoder: ", distanceCounts);
	SmartDashboard::PutNumber("Calculated Angle: ", calibratedAngle);
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
