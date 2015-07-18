// this is a simple program to generate data
// data transmitted via serial port.
// 

void setup()
{
 Serial.begin(9600); 
}

void loop()
{
 
 for(int i=0 ; i<100 ; i++)
 {
  Serial.println(i);
  Serial.println(",");
  delay(500);
 }
}
