#include <WPILib.h>
#include "ctre/Phoenix.h"
#include <SwerveModule.h>
#include <Prefs.h>

SwerveModule::SwerveModule(int driveMotorOne, int driveMotorTwo, int turnMotor):
a_DriveMotorOne(driveMotorOne),
a_DriveMotorTwo(driveMotorTwo),
a_TurnMotor(turnMotor)
{

}

void SwerveModule::UpdateRaw(float driveSpeed, float rotationSpeed)
{
	float scalar = 1.0; // Full Speed is 1.0

	a_DriveMotorOne.Set(scalar * driveSpeed); // Because this method is just for
	a_DriveMotorTwo.Set(scalar * driveSpeed); // mechanically testing the modules,
	a_TurnMotor.Set(scalar * rotationSpeed); // I've applied a scalar for safety.
}

void SwerveModule::UpdateSpeed(float driveSpeed)
{
	float scalar = 0.3; // Full Speed is 1.0
	a_DriveMotorOne.Set(scalar * driveSpeed);
	a_DriveMotorTwo.Set(scalar * driveSpeed);
}

void SwerveModule::UpdateAngle(float desiredAngle) // -180 < angle < 180
{
	float currentAngle = GetAngle();

	//  Positive Motor Speed = Unit-Circle (counter-clockwise)
	float turnSpeed = 0.15;
	if(currentAngle < desiredAngle && currentAngle - desiredAngle > -180)
	{
		a_TurnMotor.Set(-turnSpeed);
	}
	else if(currentAngle < desiredAngle && currentAngle - desiredAngle < -180)
	{
		a_TurnMotor.Set(turnSpeed);
	}
	else if(currentAngle > desiredAngle && currentAngle - desiredAngle > 180)
	{
		a_TurnMotor.Set(-turnSpeed);
	}
	else if(currentAngle > desiredAngle && currentAngle - desiredAngle < 180)
	{
		a_TurnMotor.Set(turnSpeed);
	}
	else if(currentAngle - desiredAngle == 180 || currentAngle - desiredAngle == -180)
	{
		a_TurnMotor.Set(turnSpeed);
	}
}

void SwerveModule::UpdateJason(float xInput, float yInput, float zInput) // janky, untested, and more of a outline, but theo works
{
	double xIn;
	double yIn;
	// double zIn;

	xIn = -1.0 * xInput;
	yIn = yInput;

	double desiredAngle = (atan2(xIn, yIn) * 180 / 3.1415);
	double currentAngle = GetAngle();
	SmartDashboard::PutNumber("Desired Angle: ", desiredAngle);

	float r = sqrt(pow(xInput, 2) + pow(yInput, 2)); // Finds the magnitude of the Joystick or the "r" in a polar coordinate system
	if(r > 1.0) 
	{
		r = 1.0; // For Tim, makes sure magnitude doesn't go over 1
	}
	r = r * 0.15; // For testing purposes, we will scale the input
	
	/*
	 * if(currentAngle > desiredAngle && currentAngle - desiredAngle < 180)
	{
		a_TurnMotor.Set(0.3);
	}
	else if(currentAngle > desiredAngle && currentAngle - desiredAngle > 180)
	{
		a_TurnMotor.Set(-0.3);
	}
	else if(currentAngle < desiredAngle && currentAngle - desiredAngle > 180)
	{
		a_TurnMotor.Set(-0.3);
	}
	else if(currentAngle < desiredAngle && currentAngle - desiredAngle < 180)
	{
		a_TurnMotor.Set(0.3);
	}
	// This (theo) moves the turn motor the shortest distance to the desired angle from the current angle
	 */
	// a_DriveMotorOne.Set(r);
	// a_DriveMotorTwo.Set(r); // Moves the drive motors at the calculated magnitude
}

void SwerveModule::ZeroEncoders(void)
{
	a_DriveMotorOne.SetSelectedSensorPosition(0, 0, 0);
	a_TurnMotor.SetSelectedSensorPosition(0, 0, 0);
}

float SwerveModule::GetAngleRaw(void)
{
	float ret;
	ret = a_TurnMotor.GetSelectedSensorPosition(0);
	return ret;
}

float SwerveModule::GetAngle(void)
{
	float count;
	count = GetAngleRaw(); // Returns raw value from the encoder

	float ret = ((count / COUNTS_PER_ROTATION) * 360); // Rotations * Degrees per rotation

	ret = (-1 * (int) ret % 360); // Converts counts to int casts it between 0 and 360 degrees

	if(ret >= 180) // Restricting 0 to 360 to between +/- 180
	{
		ret -= 360;
	}


	return ret;
}

float SwerveModule::GetDistanceRaw(void)
{
	float ret;
	ret = a_DriveMotorOne.GetSelectedSensorPosition(0);
	return ret;
}

float SwerveModule::GetDistanceIn(void)
{
	float count;
	count = GetDistanceRaw();


	float ret = ((count / (COUNTS_PER_ROTATION * GEAR_RATIO_SCALAR)) * WHEEL_CIRCUM_IN);

	return ret;
}

float SwerveModule::GetDistanceCm(void)
{
	float count;
	count = GetDistanceRaw();


	float ret = ((count / (COUNTS_PER_ROTATION * GEAR_RATIO_SCALAR)) * WHEEL_CIRCUM_CM);

	return ret;
}

float SwerveModule::GetCurrentOP(int id)
{
	float ret;
	if(id == FL_DRIVE_ONE_ID) {
	ret = a_DriveMotorOne.GetOutputCurrent();
	}
	else if(id == FL_DRIVE_TWO_ID) {
	ret = a_DriveMotorTwo.GetOutputCurrent();
	}
	else if(id == FL_TURN_ID) {
		ret = a_TurnMotor.GetOutputCurrent();
	}
	else
	{
		ret = 0;
	}

	return ret;
}

float SwerveModule::GetVoltageOP(int id)
{
	float ret;
	if(id == FL_DRIVE_ONE_ID) {
	ret = a_DriveMotorOne.GetMotorOutputVoltage();
	}
	else if(id == FL_DRIVE_TWO_ID) {
	ret = a_DriveMotorTwo.GetMotorOutputVoltage();
	}
	else if(id == FL_TURN_ID) {
		ret = a_TurnMotor.GetMotorOutputVoltage();
	}
	else
	{
		ret = 0;
	}

	return ret;
}

SwerveModule::~SwerveModule(void)
{

}
