/*
  Enums.hpp

   Created on: Jan 3, 2020
   Author: 5561
 */

#pragma once
 
#ifndef ENUMS
#define ENUMS 

typedef enum T_RobotCorner
{
  E_FrontLeft,
  E_FrontRight,
  E_RearLeft,
  E_RearRight,
  E_RobotCornerSz
} T_RobotCorner;

typedef enum T_RoboShooter
{
  E_TopShooter,
  E_BottomShooter,
  E_RoboShooter
} T_RoboShooter;

typedef enum T_WheelOfFortuneColor
{
  E_Red,
  E_Yellow,
  E_Blue,
  E_Green,
  E_Unknown
} T_WheelOfFortuneColor;

#endif
