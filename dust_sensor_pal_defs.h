/**
 * @author Ashutosh Singh Parmar
 * @file dust_sensor_pal_defs.h
 * @brief This file contains definitions required by platform abstraction layer APIs.
 * 
 * @note PAL stands for PLATFORM ABSTRACTION LAYER
*/
#ifndef DUST_SENSOR_PAL_DEFS
#define DUST_SENSOR_PAL_DEFS

/**
 * Include platform specific libraries here.
*/
#include <Arduino.h>

typedef struct dust_sensor_io{
    uint8_t led;
    uint8_t ain;
}dust_sensor_io;

/**
 * If platform specific header files do not include the definitions for types:
 * 1. uint8_t : The PAL APIs consider this type to be 8 bit unsigned type. Uncomment and modify (if required).
 * 2. uint32_t : The PAL APIs consider this type to be 32 bit unsigned type. Uncomment and modify (if required).
 * 
 * Then, uncomment the following lines and modify them suitably.
*/
//typedef unsigned char uint8_t;
//typedef unsigned int uint32_t;


#endif