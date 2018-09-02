
#ifndef SRC_SWERVEDRIVE_H_
#define SRC_SWERVEDRIVE_H_

#include <WPILib.h>
#include "ctre\Phoenix.h"
#include <SwerveModule.h>

class SwerveDrive
{
public:

	SwerveDrive(void);
	~SwerveDrive(void);

	void CrabDrive(double xIn, double yIn, double zIn);
private:
	SwerveModule FL_SwerveModule;
};

#endif /* SRC_SWERVEDRIVE_H_ */
