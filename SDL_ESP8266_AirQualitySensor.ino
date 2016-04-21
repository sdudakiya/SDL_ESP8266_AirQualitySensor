#include <Wire.h>
#include "MAdafruit_ADS1015.h"

// Air Quality Code


int current_quality = -1;
Adafruit_ADS1115 ads;

#include "AirQualityLibrary.h"

void setup()
{
  Serial.begin(115200);

  // Note:  Some ESP8266 modules are wired backwards (4 is 5 and 5 is 4).   It this doesn't work, try the other way
  Wire.begin(4, 5);
//  Wire.begin(5, 4);

  Serial.println("------------------------------");
  Serial.println("------------------------------");

  Serial.println("OurWeather - Air Quality Sensor Test");

  Serial.println("------------------------------");
  Serial.println("------------------------------");
  Serial.println();


  ads.begin();


  
  Serial.println("Completed Setup");
}

long currentAirQuality;

void loop()
{
  //Serial.println();
  //Serial.println("-----Sampling Air Quality-----");


  int16_t ad0 = ads.readADC_SingleEnded(0);
 

  Serial.print("ad0=");
  Serial.println(ad0);

  

  currentAirQuality = getAirQuality();



  Serial.print("currentAirQuality=");
  Serial.println(currentAirQuality);
  Serial.println("------------------------------");
  delay(1000);


}



