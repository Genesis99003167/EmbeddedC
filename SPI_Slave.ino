#include<SPI.h>
volatile boolean value_obtained;
volatile boolean Slave_obtained;
void setup()
{
  Serial.begin(9600);
  pinMode(MISO, OUTPUT);
  pinMode(10, INPUT);
  digitalWrite(10, LOW);
  SPCR |= _BV(SPE);
  value_obtained = false;
  SPI.attachInterrupt();
  Serial.print("SYSTEM STARTING...");
  delay(2000);
  Serial.print("SYSTEM READY TO START...");
}
ISR(SPI_STC_vect)
{
  Slave_obtained = SPDR;
  value_obtained = true;
}
void loop()
{
  if (value_obtained)
  {
    if (Slave_obtained == HIGH)
    {
      value_obtained = false;
      Serial.print("\n Night Lamp Switched ON\n");
      delay(1000);
    }
  }
  else
  {
    value_obtained = false;
    Serial.print("\n Night Lamp Switched OFF\n");
    delay(1000);
  }
}
