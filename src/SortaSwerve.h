/*
 * SortaSwerve.h
 *
 *  Created on: Aug 3, 2018
 *      Author: Time
 */
#include <WPILib.h>

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

	~SortaSwerve(void);
private:

};



#endif /* SRC_SORTASWERVE_H_ */
