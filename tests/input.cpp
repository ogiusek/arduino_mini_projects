const int btnPin = 10;
const int lightPin = 8;
bool pressed = false;

void setup() {
  Serial.begin(9600); // load terminal

  pinMode(btnPin, INPUT_PULLUP);
  pinMode(lightPin, OUTPUT);
}

void loop() {
  bool state = digitalRead(btnPin);
  digitalWrite(lightPin, state == pressed ? HIGH : LOW);
}
