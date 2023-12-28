#define DELAY 1000
bool **numberStates = new bool*[10]{
  new bool[8]{1, 1, 1, 0, 1, 1, 1, 0},  // 0
  new bool[8]{0, 0, 1, 0, 0, 1, 0, 0},  // 1
  new bool[8]{1, 0, 1, 1, 1, 0, 1, 0},  // 2
  new bool[8]{1, 0, 1, 1, 0, 1, 1, 0},  // 3
  new bool[8]{0, 1, 1, 1, 0, 1, 0, 0},  // 4
  new bool[8]{1, 1, 0, 1, 0, 1, 1, 0},  // 5
  new bool[8]{1, 1, 0, 1, 1, 1, 1, 0},  // 6
  new bool[8]{1, 0, 1, 0, 0, 1, 0, 0},  // 7
  new bool[8]{1, 1, 1, 1, 1, 1, 1, 0},  // 8
  new bool[8]{1, 1, 1, 1, 0, 1, 1, 0}   // 9 
};

int digitsPins[4] = {40, 43, 44, 51};
int lightsPins[8] = {41, 42, 45, // top, left, right
                     50, // floor between
                     46, 49, 47, // left, right, floor
                     48 // dot
                     };

unsigned long ticks = 0; // counter

void toggleDigit(int digitPin, bool on){
  digitalWrite(digitPin, !on ? LOW : HIGH);
}

void setLights(bool *states = new bool[8]{0, 0, 0, 0, 0, 0, 0, 0}){
  for(int i = 0; i < 8; i++)
    digitalWrite(lightsPins[i], states[i] ? LOW : HIGH);
}

void printDigit(char letter, int digitPin){
  setLights(numberStates[letter]);  // set digit lights
  toggleDigit(digitPin, true);      // select digit
  delayMicroseconds(DELAY);
  toggleDigit(digitPin, false);     // unselect digit
}

void setup() {
  for(int i = 0; i < 4; i++)
    pinMode(digitsPins[i], OUTPUT);
  for(int i = 0; i < 8; i++)
    pinMode(lightsPins[i], OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int seconds = ticks / 100;
  char numText[4] = {(seconds / 1000) % 10,
                     (seconds / 100) % 10,
                     (seconds / 10) % 10,
                     (seconds / 1) % 10};
  for(int i = 0; i < 4; i++){
    printDigit(numText[i], digitsPins[i]);
    delayMicroseconds(DELAY);
  }
  ticks++;
  delayMicroseconds(DELAY * 2);
}
