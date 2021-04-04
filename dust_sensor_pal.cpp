/**
 * @author Ashutosh Singh Parmar
 * @file dust_sensor_pal_.c
 * @brief This file contains platform abstraction layer APIs.
*/

#include "dust_sensor_pal.h"

static uint8_t led_pin;
static uint8_t ain_pin;

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
void pal_io_init(void * data)
{
    /* !!...Platform specific code here...!! */
    led_pin = ((dust_sensor_io*)data)->led;
    ain_pin = ((dust_sensor_io*)data)->ain;

    pinMode( led_pin, OUTPUT);
    //pinMode( ain_pin, INPUT);
}

/**
 * @brief This API will be called by the higher level code to set the logical state of the LED pin.
 * 
 * @param uint8_t The state - 1 or 0.
 * 
 * @return NOTHING.
 * 
 * @note Put the platform specific code that can set the state of LED io line.
*/
void pal_led_set_state(uint8_t state)
{
    /* !!...Platform specific code here...!! */
    digitalWrite( led_pin, state);
}

/**
 * @brief This API will be called by the higher level code to read the output voltage of the dust sensor.
 * 
 * @param void NONE
 * 
 * @return double : output voltage of the dust sensor in milli Volts.
 * 
 * @note Put the platform specific code that can get the ADC reading and convert it to milli Volts.
*/
double pal_get_reading(void)
{
    /* !!...Platform specific code here...!! */
    double reading = analogRead(ain_pin);

    reading = 4.8828 * reading;   // 5000.0/1024 = 4.8828

    return reading;
}