/*
  coolant_control.c - coolant control methods
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

#include "system.h"
#include "coolant_control.h"
#include "protocol.h"
#include "gcode.h"
extern void rampsInitCoolant();
extern void rampsInitSpindle();
extern void rampsInitSteppers();
extern void rampsWriteDisable(uint8_t value);
extern void rampsWriteSteps(uint8_t value);
extern void rampsWriteDirections(uint8_t value);
extern void rampsStartSpindle();
extern void rampsStopSpindle();
extern void rampsLeftSpindle();
extern void rampsRightSpindle();
extern void rampsCoolantOn();
extern void rampsCoolantOff();

void coolant_init() {
    // COOLANT_FLOOD_DDR |= (1 << COOLANT_FLOOD_BIT);
    rampsInitCoolant();
  #ifdef ENABLE_M7
    COOLANT_MIST_DDR |= (1 << COOLANT_MIST_BIT);
  #endif
  coolant_stop();
}


void coolant_stop() {
    // COOLANT_FLOOD_PORT &= ~(1 << COOLANT_FLOOD_BIT);
    rampsCoolantOff();
  #ifdef ENABLE_M7
    COOLANT_MIST_PORT &= ~(1 << COOLANT_MIST_BIT);
  #endif
}


void coolant_run(uint8_t mode)
{
  if (sys.state == STATE_CHECK_MODE) { return; }

  protocol_auto_cycle_start();   //temp fix for M8 lockup
  protocol_buffer_synchronize(); // Ensure coolant turns on when specified in program.
  if (mode == COOLANT_FLOOD_ENABLE) {
        //COOLANT_FLOOD_PORT |= (1 << COOLANT_FLOOD_BIT);
        rampsCoolantOn();

  #ifdef ENABLE_M7  
    } else if (mode == COOLANT_MIST_ENABLE) {
      COOLANT_MIST_PORT |= (1 << COOLANT_MIST_BIT);
  #endif

  } else {
    coolant_stop();
  }
}
