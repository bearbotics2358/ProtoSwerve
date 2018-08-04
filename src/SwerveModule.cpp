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

}

SwerveModule::~SwerveModule(void)
{

}
