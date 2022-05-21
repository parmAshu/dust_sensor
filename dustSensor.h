/**
 * @author Ashutosh Singh Parmar
 * @file dust_sensor.h
 * @brief This file contains declarations of core driver APIs.
*/
#ifndef DUST_SENSOR
#define DUST_SENSOR

#include "dust_sensor_pal.h"

/**
 * @brief Default K value - 5 V/mg/m^3
*/
#define DEFAULT_K 5.0
/**
 * @brief Default Voc value - 0.6V
*/
#define DEFAULT_VOC 0.6
/**
 * @brief Default Vmax - 3.5V
*/
#define DEFAULT_VMAX 3.5

/**
 * @brief dust_sensor class - contains all the APIs to access the dust sensor
*/
class dust_sensor
{

    private:
        /**
         * @brief number of readings to take for averaging
        */
        uint8_t num_readings;

        /**
         * @brief The slope of dust concentation vs voltage (in mg/m^3/V) curve (assmed to be linear)
        */
        double M;

        /**
         * @brief The y intercept of dust concentration vs voltage curve (in mg/m^3).
         */
        double C;

        /**
         * @brief Maximum output voltage till the curve is linear
        */
        double Vmax;

    public:
        /**
         * @brief This will hold the latest dust concetration reading (in ug/m^3).
        */
        double dust_conc;

        /**
         * @brief Class constructor
         * 
         * @param void * : pointer to a custom structure that will be passed as it is to the PAL initilization API.
        */
        dust_sensor(void *, uint8_t);

        /**
         * @brief This API is used to set the number of readings that are taken for one function call of getConcentration.
         * 
         * @param uint8_t : number of repeated measurements
         * 
         * @return NOTHING
        */
        void setNumRepeats(uint8_t);

        /**
        * @brief This API obtains the raw output voltage of sensor in milliVolts.
        *
        * @param NONE   
        *
        * @return double : the output voltage of the sensor in millivolts.
        */
        double getVoltage(void);

        /**
         * @brief This API takes 'readings' number of dust conc meaurements and will average them. The average result will be
         * returned and stored in the 'dust_conc' variable.
         * 
         * @param NONE
         * 
         * @return double : The dust concentration in ug/m^3
        */
        double getConcentration(void);

        /**
         * @brief This API takes single measurement of dust conc and will return and store it.
         * 
         * @param NONE
         * 
         * @return double : The dust concentration in ug/m^3
        */
        double getConcentrationSingle(void);

};

#endif