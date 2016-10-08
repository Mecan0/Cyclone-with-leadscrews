/*
  spindle_control.h - spindle control methods
  Part of Grbl v0.9

  Copyright (c) 2012-2014 Sungeun K. Jeon

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/
/* 
  This file is based on work from Grbl v0.8, distributed under the 
  terms of the MIT-license. See COPYING for more details.  
    Copyright (c) 2009-2011 Simen Svale Skogsrud
    Copyright (c) 2012 Sungeun K. Jeon
*/ 

#ifndef spindle_control_h
#define spindle_control_h 


// Initializes spindle pins and hardware PWM, if enabled.
void spindle_init();

// Sets spindle direction and spindle rpm via PWM, if enabled.
void spindle_run(uint8_t direction, float rpm);

// Kills spindle.
void spindle_stop();

#endif
