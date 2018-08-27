#include <WPILib.h>
#include "ctre/Phoenix.h"

#ifndef SRC_SWEREMODULE_H_
#define SRC_SWEREMODULE_H_

class SwerveModule {
public:
	SwerveModule(int driveMotorOne, int driveMotorTwo, int turnMotor); // Takes CAN IDs for the different talons so this class can be reused for more than one module.

	void UpdateCartesian(float xInput, float yInput); // Will calculate the polar coords and automatically determine the angle and speed.
	void UpdatePolar(float radius, float angle); // Theo float for angle, method will be used for higher level classes that just feed it polar coords.
	void UpdateRaw(float driveSpeed, float rotationSpeed); // Method for mechanically testing swerve modules, will literally set the drive talons to a specific speed.
	void UpdateAngle(float angle); // Angle in degrees

	void ZeroEncoders(void);
	float GetAngleRaw(void);
	float GetAngle(void);

	float GetDistanceRaw(void);
	float GetDistanceIn(void);
	float GetDistanceCm(void);

	float GetCurrentOP(int id);
	float GetVoltageOP(int id);

	~SwerveModule(void);
private:
	WPI_TalonSRX a_DriveMotorOne;
	WPI_TalonSRX a_DriveMotorTwo;
	WPI_TalonSRX a_TurnMotor;
};



#endif /* SRC_SWEREMODULE_H_ */
