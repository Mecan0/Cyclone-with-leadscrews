// GRBL RAMPS 1.4 port
// By ArSi arsi@arsi.sk
//**************************************************************************************
// Modifications for Cyclone PCB Factory by carlosgs
// Check README.md for details
//***************************************************************************************



//#Grbl - An embedded g-code interpreter and motion-controller for the Arduino/AVR328 microcontroller
//
//***

//Grbl is a no-compromise, high performance, low cost alternative to parallel-port-based motion control for CNC milling. It will run on a vanilla Arduino //(Duemillanove/Uno) as long as it sports an Atmega 328. 

//The controller is written in highly optimized C utilizing every clever feature of the AVR-chips to achieve precise timing and asynchronous operation. It is able to //maintain up to 30kHz of stable, jitter free control pulses.

//It accepts standards-compliant g-code and has been tested with the output of several CAM tools with no problems. Arcs, circles and helical motion are fully supported, //as well as, all other primary g-code commands. Macro functions, variables, and most canned cycles are not supported, but we think GUIs can do a much better job at //translating them into straight g-code anyhow.

//Grbl includes full acceleration management with look ahead. That means the controller will look up to 18 motions into the future and plan its velocities ahead to //deliver smooth acceleration and jerk-free cornering.

// [Licensing](https://github.com/grbl/grbl/wiki/Licensing): Grbl v0.9 is free software, released under the GPLv3 license. Obsolete versions of Grbl, v0.8 and prior, //are released under the permissive MIT-license. This will ensure Grbl will always be an open-source project while making the code permissive for others.

//For more information and help, check out our **[Wiki pages!](https://github.com/grbl/grbl/wiki)** If you find that the information is out-dated, please to help us //keep it updated by editing it or notifying our community! Thanks!

//Lead Developer [_2011 - Current_]: Sonny Jeon, Ph.D. (USA)

//Lead Developer [_2009 - 2011_]: Simen Svale Skogsrud (Norway). aka The Originator/Creator/Pioneer/Father of Grbl.






#include "system.h"
#include "nuts_bolts.h"
#include "eeprom.h"
#include "gcode.h"

#include "config.h"
#include "defaults.h"
#include "settings.h"
#include "fastio.h"

#include "stepper.h"
#include "planner.h"
#include "report.h"
#include "serial.h"
#include "cpu_map.h"
#include "limits.h"
#include "motion_control.h"
#include "spindle_control.h"
#include "protocol.h"
#include "probe.h"
#include "print.h"
#include "coolant_control.h"





