const int trigPin = 9;
const int echoPin = 10;

const int SPEED_CONST = 58; // divide by this to get distance from distance sensor in cm 

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.println("Finished setup");
}

void loop()
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long time = pulseIn(echoPin, HIGH);
  Serial.println(time/SPEED_CONST);
  delay(500);
}