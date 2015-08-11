// this is a simple program to generate data
// data transmitted via serial port.
// 

//-----------List down the variables
int data [500];
int index =0;
int increment;
int updateinterval;
int updateendtime;
int endtime;
//read sensor (Now just generate Data)
class Sensor
{
  
  public:
  unsigned long lastupdate;
  unsigned long timer;
  int sensorVal;
  
  Sensor(int interval, int endtime)
  {
    //-------------set variables value
    updateinterval = interval;
    updateendtime =endtime;
    sensorVal =0;
    increment =1;
    timer = millis();
  }

  void update()
  {
    //---------------call every 0.1 sec
    if((millis() -lastupdate) > updateinterval)
    {
      //loop of data here
     lastupdate = millis();
      sensorVal += increment;
      index += increment ;
      data [index] =sensorVal;
      Serial.println(sensorVal);
    }
    
  }
  
  
  void kill()
  {
    if ( (millis()- endtime) > updateendtime*1000)
    {
      data [index] = '\0';
      Serial.println("The end of data collection");
      endtime = millis();
      Serial.end();
    }
  }
};

Sensor sample(100, 10);

void setup()
{
 Serial.begin(9600); 

}
 
 
void loop()
{
  
  sample.update();
  sample.kill();

}
