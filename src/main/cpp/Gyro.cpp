#include <frc/smartdashboard/SmartDashboard.h>
#include "AHRS.h"
#include <frc/DriverStation.h>

AHRS *NavX;

float gyro_angleprev;
int gryo_loopcount = 0;

void GyroRobotInit()
{
    try{
      NavX = new AHRS(SPI::Port::kMXP);
    }
    catch(const std::exception e){
      std::string err_string = "Error instantiating navX-MXP:  ";
      err_string += e.what();
      DriverStation::ReportError(err_string.c_str());
    }
}

void GyroTeleInit() 
{
    NavX->ZeroYaw();
}
void Gyro() {

float gyro_currentyaw = NavX->GetYaw();
  
  //Check to see if gyro angle flips over 180 or -180
  if(175 <= abs(gyro_angleprev))
  {
    if(gyro_angleprev < 0 && gyro_currentyaw > 0)
    {
      gryo_loopcount -= 1;
    } else if (gyro_angleprev > 0 && gyro_currentyaw < 0)
    {
      gryo_loopcount += 1;
    }
  }
float finalangle = ((float)gryo_loopcount * 360) + gyro_currentyaw;

  frc::SmartDashboard::PutNumber("NavX Raw Yaw", NavX->GetYaw());
  frc::SmartDashboard::PutNumber("NavX accum angle", finalangle);
  gyro_angleprev = gyro_currentyaw;

}