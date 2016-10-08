/* 
 * File:   ramps.h
 * Author: arsi
 *
 * Created on September 1, 2014, 4:44 PM
 */
#ifndef RAMPS_H
#define	RAMPS_H


#ifdef	__cplusplus
extern "C" {
#endif

#include"cpu_map.h"
#include<stdint.h>
#include"fastio.h"

#define CHECK(var,pos) ((var) & (1<<(pos)))

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

    inline void rampsCoolantOn() {
        WRITE(COOLANT_FLOOD_PIN, 1);
    }

    inline void rampsCoolantOff() {
        WRITE(COOLANT_FLOOD_PIN, 0);
    }

    inline void rampsLeftSpindle() {
        WRITE(SPINDLE_DIRECTION_PIN, 1);
    }

    inline void rampsRightSpindle() {
        WRITE(SPINDLE_DIRECTION_PIN, 0);
    }

    inline void rampsStartSpindle() {
        WRITE(SPINDLE_ENABLE_PIN, 1);
    }

    inline void rampsStopSpindle() {
        WRITE(SPINDLE_ENABLE_PIN, 0);
    }

    inline void rampsInitCoolant() {
        SET_OUTPUT(COOLANT_FLOOD_PIN);
    }

    inline void rampsInitSpindle() {
        SET_OUTPUT(SPINDLE_ENABLE_PIN);
        SET_OUTPUT(SPINDLE_DIRECTION_PIN);
    }

/**
     * Perform port direction init for ramps for steppers
     */
    inline void rampsInitSteppers() {
        SET_OUTPUT(X_STEP_PIN);
        SET_OUTPUT(Y_STEP_PIN);
        SET_OUTPUT(Z_STEP_PIN);
        SET_OUTPUT(X_DIR_PIN);
        SET_OUTPUT(Y_DIR_PIN);
        SET_OUTPUT(Z_DIR_PIN);
        SET_OUTPUT(X_ENABLE_PIN);
        SET_OUTPUT(Y_ENABLE_PIN);
        SET_OUTPUT(Z_ENABLE_PIN);
    }

/**
     * Perform set of EN driver signal
     * @param value
     */
    inline void rampsWriteDisable(uint8_t value) {
        if (CHECK(value, STEPPERS_DISABLE_BIT)) {
            WRITE(X_ENABLE_PIN, 1);
            WRITE(Y_ENABLE_PIN, 1);
            WRITE(Z_ENABLE_PIN, 1);
        } else {
            WRITE(X_ENABLE_PIN, 0);
            WRITE(Y_ENABLE_PIN, 0);
            WRITE(Z_ENABLE_PIN, 0);
        }
    }

/**
     * write stepper pulse
     * @param value
     */
    inline void rampsWriteSteps(uint8_t value) {
        if (CHECK(value, X_STEP_BIT)) {
            WRITE(X_STEP_PIN, 1);
        } else {
            WRITE(X_STEP_PIN, 0);
        }
        if (CHECK(value, Y_STEP_BIT)) {
            WRITE(Y_STEP_PIN, 1);
        } else {
            WRITE(Y_STEP_PIN, 0);
        }
        if (CHECK(value, Z_STEP_BIT)) {
            WRITE(Z_STEP_PIN, 1);
        } else {
            WRITE(Z_STEP_PIN, 0);
        }

    }

/**
     * set stepper direction
     * @param value
     */
    inline void rampsWriteDirections(uint8_t value) {
        if (CHECK(value, X_DIRECTION_BIT)) {
            WRITE(X_DIR_PIN, 1);
        } else {
            WRITE(X_DIR_PIN, 0);
        }
        if (CHECK(value, Y_DIRECTION_BIT)) {
            WRITE(Y_DIR_PIN, 1);
        } else {
            WRITE(Y_DIR_PIN, 0);
        }
        if (CHECK(value, Z_DIRECTION_BIT)) {
            WRITE(Z_DIR_PIN, 1);
        } else {
            WRITE(Z_DIR_PIN, 0);
        }
    }


#ifdef	__cplusplus
}
#endif

#endif	/* RAMPS_H */

