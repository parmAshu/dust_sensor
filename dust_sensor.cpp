/**
 * @author Ashutosh Singh Parmar
 * @file dust_sensor.cpp
 * @brief This file contains core driver APIs.
*/

#include "dust_sensor.h"

/**
* @brief Class constructor
* 
* @param void * : pointer to a custom structure that will be passed as it is to the PAL initilization API.
*/
dust_sensor :: dust_sensor(void * _data_, uint8_t repeats)
{
    /**
     * Initializing the IO ports
    */
    pal_io_init(_data_);

    pal_led_set_state(1);

    if(repeats==0)
        this->num_readings=5;
    else 
        this->num_readings=repeats;

    this->M = 1 / DEFAULT_K;

    this->C =  (-1 * DEFAULT_VOC) / DEFAULT_K;

    this->Vmax = DEFAULT_VMAX;

    this->dust_conc=0.0;
}

/**
* @brief This API is used to set the number of readings that are taken for before returning the average concentration.
* 
* @param uint8_t : number of repeated measurements
* 
* @return NOTHING
*/
void dust_sensor :: setNumRepeats(uint8_t repeats)
{
    this->num_readings=repeats;
}

/**
* @brief This API obtains the raw output voltage of sensor in milliVolts.
*
* @param NONE
*
* @return double : the output voltage of the sensor in millivolts.
*/
double dust_sensor :: getVoltage(void)
{
    double Vo;
    pal_led_set_state(0);
    pal_delay_us(280);
    Vo = pal_get_reading();
    pal_delay_us(40);
    pal_led_set_state(1);
    pal_delay_ms(10);
    return Vo;
}

/**
* @brief This API takes 'readings' number of dust conc meaurements and will average them. The average result will be
* returned and stored in the 'dust_conc' variable.
* 
* @param NONE
* 
* @return double : The dust concentration in ug/m^3
*/
double dust_sensor :: getConcentration(void)
{
    double Vavg=0.0;

    for(uint8_t i=1; i<=this->num_readings; i++)
    {
        Vavg += this->getVoltage();
    }

    //average voltage in millivolts
    Vavg = Vavg / this->num_readings;

    this->dust_conc = this->M * Vavg + 1000.0 * this->C;

    if( this->dust_conc < 0 )
        this->dust_conc=0.0;

    return this->dust_conc; 
}

/**
* @brief This API takes single measurement of dust conc and will return and store it.
* 
* @param NONE
* 
* @return double : The dust concentration in ug/m^3
*/
double dust_sensor :: getConcentrationSingle(void)
{
    this->dust_conc = this->M * this->getVoltage() + 1000.0 * this->C;

    if( this->dust_conc < 0 )
        this->dust_conc=0.0;

    return this->dust_conc;
}