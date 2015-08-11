// this is a simple program to generate data
// data transmitted via serial port.
// 

//-----------List down the variables
int data [500];
int index =0;
int duration = 100 ;

//read sensor (Now just generate Data)
class Sensor
{
  public:
  unsigned long previousTime;
  unsigned long currentTime;
  unsigned long timerTime;
  int sensorVal;
  
  Sensor(int duration)
  {
    //-------------set variables value
    previousTime = 0;
    sensorVal =0;
  };
  
  void update()
  {
    currentTime = millis();
    //timerTime = millis() + duration*1000;
    
    //---------------call every 0.1 sec
    if ( currentTime -previousTime >=100)
    {
      //loop of data here
      previousTime = currentTime;
      sensorVal += 1;
      index += 1 ;
      Serial.println(sensorVal);
      data [index] =sensorVal;
      
     //WWhen the time is up
      if (currentTime >= duration*1000)
    {
      data[index+1] = '\0'; //terminate the string
      Serial.println("Data End");
      
  }
    }
  }
};


void setup()
{
 Serial.begin(9600); 

}
 
 
void loop()
{
  Sensor simple(Serial.read());
  
   
   simple.update();
}
