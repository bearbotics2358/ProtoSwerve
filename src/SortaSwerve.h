#include <WPILib.h>
#include <SwerveModule.h>

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

	Joystick a_Joystick1;

	SwerveModule FL_SwerveModule;
};



#endif /* SRC_SORTASWERVE_H_ */
