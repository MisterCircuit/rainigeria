#include <Streaming.h>

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Serial << "Current millis: " << millis() << endl;
  delay(1000);
}