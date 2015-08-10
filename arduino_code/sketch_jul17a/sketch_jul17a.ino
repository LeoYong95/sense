// this is a simple program to generate data
// data transmitted via serial port.
// 
int msg;
void setup()
{
 Serial.begin(9600); 
}
 
 
void loop()
{
 
 for(int i=0 ; i<100 ; i++)
 {
  Serial.print(i);
  Serial.print("\n");
  delay(100);
 }
 
 if (Serial.available() > 0)
 {
   msg = Serial.read();
   if (msg = 0 )
   {
     Serial.end();
   }
 }
 
}
