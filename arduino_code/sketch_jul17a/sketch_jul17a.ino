#include <SoftwareSerial.h>

/* this is a simplpe code to read sensor and send it over serial to the computer
 
 This have time function that allow user to:
 
 1) Select the time interval for individual data.
 2) Set the duration for data collection.
 
 Auth: LEO YONG
 
 LeoYong95/sense
 
*/ 

//-----------List down the variables
int data [500]; //-----Limit data to 500 data at one collection.
int index =0; 
int increment;
int updateinterval;
int updateendtime;
int endtime;


//-------------read sensor ( for now just generate Data)
class Sensor
{
  
  public:
//------------List Down variables
  unsigned long lastupdate;
  int sensorVal;
  
//------------Constructor  
  Sensor(int interval, int endtime)
  {
//-------------set variables value
    updateinterval = interval;
    updateendtime =endtime;
    sensorVal =0;
    increment =1;
    
  }
  
//--------------setup the Serial
void Setup()
{
   Serial.begin(9600);
  
}

//--------------call this function for every interval
  void update()
  {

    if((millis() -lastupdate) > updateinterval)
    {
     lastupdate = millis();
      sensorVal += increment;
      index += increment ;
      data [index] =sensorVal; //---------Input data to the array
      Serial.println(sensorVal);
    }
    
  }
  
//------------call this function for every data collection  
  void kill()
  {
    if ( (millis()- endtime) > updateendtime*1000)//-----------Updateendtime is in seconds (convert to milliseconds)
    {
      data [index] = '\0';
      Serial.println("The end of data collection");
      Serial.println("Close the terminal to end this session of data collection.")
      endtime = millis();
      Serial.end();
    }
  }
};

//--------let the duration for data be 10s and interval of data be 0.1s
Sensor sample(100, 10);

void setup()
{
   sample.Setup();
  
}

void loop()
{
 
  sample.update();
  sample.kill();

}
