#include <WPILib.h>
#include <SwerveModule.h>
#include <SwerveDrive.h>

#ifndef SRC_SORTASWERVE_H_
#define SRC_SORTASWERVE_H_

class SortaSwerve : public IterativeRobot
{
public:
	SortaSwerve(void);

	void RobotInit(void);
	void RobotPeriodic(void);

	void DisabledInit(void);
	void DisabledPeriodic(void);

	void TeleopInit(void);
	void TeleopPeriodic(void);

	void AutonomousInit(void);
	void AutonomousPeriodic(void);

	void TestInit(void);
	void TestPeriodic(void);

	~SortaSwerve(void);
private:
	std::string robotState;
	bool cruiseControl;
	bool crabToggle;
	float driveSpeed;
	float rotationSpeed;

	Joystick a_Joystick1;

	SwerveModule FL_SwerveModule;
	SwerveDrive a_SwerveDrive;
};



#endif /* SRC_SORTASWERVE_H_ */
