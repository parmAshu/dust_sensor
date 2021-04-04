/**
 * @author Ashutosh Singh Parmar
 * @file dust_sensor_pal.h
 * @brief This file contains declarations of platform abstraction layer APIs.
*/
#ifndef DUST_SENSOR_PAL
#define DUST_SENSOR_PAL

/**
 * Included the header file that contains all the required type definitions.
*/
#include "dust_sensor_pal_defs.h"

/**
 * @brief This API will be called by the higher level code to suspend the execution by some milliseconds.
 * 
 * @param uint32_t _int : number of milliseconds to delay the execution.
 * 
 * @return NOTHING.
 * 
 * @note Put the platform specfic code that can produce a delay of _int milliseconds.
*/
inline void pal_delay_ms(uint32_t _int)
{
    /* !!...Platform specific code here...!! */
    delay(_int);
}

/**
 * @brief This API will be called by the higher level code to suspend the execution by some microseconds.
 * 
 * @param uint32_t _int : number of microseconds to delay the execution.
 * 
 * @return NOTHING.
 * 
 * @note Put the platform specific code that can produce a delay of _int microseconds.
*/
inline void pal_delay_us(uint32_t _int)
{
    /* !!...Platform specfic code here...!! */
    delayMicroseconds(_int);
}

/**
 * @brief This API will be called by the higher level code to initialize the IO pins which sensor is connected to.
 * 
 * @param void * pointer to some user defined structure. This structure will carry the io information povided by the user code.
 * The user code will provide this structure pointer to high level APIs which in turn will provide this pointer to this PAL API.
 * Since the information to be passed is strictly dependent upon the platform, user must define a custom structure in the file
 * 'dust_sensor_pal_defs.h'. Now, both the user and the PAL code knows abou the structure and it can carry the required information
 * from the user code to PAL code.
 * 
 * @return NOTHING
 * 
 * @note Put the platform specific code that can initialize the ios.
*/
void pal_io_init(void *);

/**
 * @brief This API will be called by the higher level code to set the logical state of the LED pin.
 * 
 * @param uint8_t The state - 1 or 0.
 * 
 * @return NOTHING.
 * 
 * @note Put the platform specific code that can set the state of LED io line.
*/
void pal_led_set_state(uint8_t);

/**
 * @brief This API will be called by the higher level code to read the output voltage of the dust sensor.
 * 
 * @param void NONE
 * 
 * @return double : output voltage of the dust sensor in Volts.
 * 
 * @note Put the platform specific code that can get the ADC reading and convert it to volts.
*/
double pal_get_reading(void);

#endif