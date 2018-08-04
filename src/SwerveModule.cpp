#include <WPILib.h>
#include "ctre/Phoenix.h"
#include <SwerveModule.h>

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
	float scalar = 0.4;

	a_DriveMotorOne.Set(scalar * driveSpeed); // Because this method is just for
	a_DriveMotorTwo.Set(scalar * driveSpeed); // mechanically testing the modules,
	a_TurnMotor.Set(scalar * rotationSpeed); // I've applied a scalar for safety.
}

SwerveModule::~SwerveModule(void)
{

}
