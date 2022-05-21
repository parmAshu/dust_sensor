#include "dustSensor.h"

dust_sensor_io LINES = {
  .led = 4,
  .ain = A0
};

dust_sensor sensor(&LINES, 5);

void setup() 
{
  Serial.begin(9600);
  delay(100);
}

void loop() 
{
  Serial.print("Output Voltage (mV):  ");
  Serial.println(sensor.getVoltage());
  Serial.print("Dust Concentration (ug/m^3):  ");
  Serial.println( sensor.getConcentration() );
  Serial.println('\n');
  delay(2000);
}
