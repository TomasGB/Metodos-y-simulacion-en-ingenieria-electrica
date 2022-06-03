
void setup()
{
    Serial.begin(9600);
  
}
void loop()
{  
  double epsilon=1,x,result;
  bool run=true;


  while (run)
  {
    epsilon /= 2;						
    x=epsilon+1;

    if (x <= 1)
    {
      run=false;
    }
  }
  result = 2 * epsilon;

  Serial.println (result, 15);
  delay (1000);
}