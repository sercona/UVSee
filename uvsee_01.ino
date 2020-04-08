/*
   uv sensor demo
   
   linux-works labs

   v1.0, 2020-apr-07
*/


#include <Arduino.h>

#define BT_SERIAL_BAUD 9600

#define PIN_UV1_SENSOR (A0)
#define PIN_UV2_SENSOR (A1)

#define AVG_CYCLES      10.0F   // read the sensor this many times (note Float format)




void setup (void)
{
  pinMode(PIN_UV1_SENSOR, INPUT);
  pinMode(PIN_UV2_SENSOR, INPUT);


  // Open serial communications and wait for port to open:
  Serial.begin(BT_SERIAL_BAUD);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  return;
}



void read_sensor (int analog_pin, int *sensorAvg)
{
  unsigned long sensorSum = 0;
  float sensor_f = 0.0;


  // average ADC values over many readings
  sensorSum = 0;
  for (int i = 0; i < AVG_CYCLES; i++)   {
    sensorSum += analogRead(analog_pin);
    delay(10);  // let the adc settle between readings
  }
  sensor_f = (float)sensorSum / (float)AVG_CYCLES;  // do all math in FP

  sensor_f *= 100.0;   // scale it up, a bit

  *sensorAvg = (int)sensor_f;   // convert back to int, for caller

  return;
}



void loop(void)
{
  int sensorVal;

  Serial.print(millis());  // timestamp
  Serial.print(", ");      // delim

  // adafruit sensor
  read_sensor(PIN_UV1_SENSOR, &sensorVal);
  Serial.print(sensorVal);
  Serial.print(", ");      // delim

  // generic sensor
  read_sensor(PIN_UV2_SENSOR, &sensorVal);
  Serial.println(sensorVal);  // final value, with newline

  delay(500);
  
  return;
}
