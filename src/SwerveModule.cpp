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

void SwerveModule::UpdateCartesian(float xInput, float yInput)
{

}

void SwerveModule::UpdatePolar(float radius, float angle)
{

}

void SwerveModule::UpdateRaw(float driveSpeed, float rotationSpeed)
{
	float scalar = 1.0; // Full Speed is 1.0

	a_DriveMotorOne.Set(scalar * driveSpeed); // Because this method is just for
	a_DriveMotorTwo.Set(scalar * driveSpeed); // mechanically testing the modules,
	a_TurnMotor.Set(scalar * rotationSpeed); // I've applied a scalar for safety.
}

void SwerveModule::UpdateAngle(float angle) // -180 < angle < 180
{
	// Will turn the swerve module to a specific angle.
	// Note: Definition will be added later, method just added as pseudo code.
}

void SwerveModule::UpdateJason(float xInput, float yInput, float zInput) // janky, untested, and more of a outline, but theo works
{

	// a_TurnMotor.Set(zInput); Would be used for turning robot or module in this case, but pointless for one wheel

	float r = sqrt(pow(xInput, 2) + pow(yInput, 2)); // Finds the magnitude of the Joystick or the "r" in a polar coordinate system
	if(r > 1.0) 
	{
		r = 1.0; // For Tim, makes sure magnitude doesn't go over 1
	}
	float desiredAngle = atan(yInput/xInput);
	float currentAngle = GetAngle() + 180;
	desiredAngle = ((int) desiredAngle % 360); // This calculates the angle we want the wheel at and gets the angle the wheel is currently at
	
	if(currentAngle > desiredAngle && currentAngle - desiredAngle < 180)
	{
		a_TurnMotor.Set(-0.5);
	}
	if(currentAngle > desiredAngle && currentAngle - desiredAngle > 180)
	{
		a_TurnMotor.Set(0.5);
	}
	if(currentAngle < desiredAngle && currentAngle - desiredAngle > 180)
	{
		a_TurnMotor.Set(0.5);
	}
	if(currentAngle < desiredAngle && currentAngle - desiredAngle < 180)
	{
		a_TurnMotor.Set(-0.5);
	}
	// This (theo) moves the turn motor the shortest distance to the desired angle from the current angle
	a_DriveMotorOne.Set(r);
	a_DriveMotorTwo.Set(r); // Moves the drive motors at the calculated magnitude
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

	ret = ((int) ret % 360); // Converts counts to int casts it between 0 and 360 degrees

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

	return ret;
}

SwerveModule::~SwerveModule(void)
{

}
