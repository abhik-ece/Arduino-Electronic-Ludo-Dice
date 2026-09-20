// ------------------------------
// Project: Arduino Electronic Dice
// Author: Abhik
// Sound logic:
// Button press  -> "I"
// Rolling sound -> "am Abhik"
// ------------------------------

int leds[] = {2, 3, 4, 5, 6, 7, 11};
int buttonPin = 8;
int buzzerPin = 10;

bool lastButtonState = HIGH;

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(leds[i], OUTPUT);
  }

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);

  randomSeed(analogRead(A0));
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  // Detect button press
  if (lastButtonState == HIGH && buttonState == LOW) {

    // 1. "I" sound on button press
    iSound();
    delay(150);

    // 2. Dice rolling + "am Abhik" sound
    for (int i = 0; i < 15; i++) {
      showDice(random(1, 7));
      amAbhikSound();
      delay(70);
    }

    // 3. Final dice value (silent)
    showDice(random(1, 7));
  }

  lastButtonState = buttonState;
}

// ------------------------------
// SOUND FUNCTIONS
// ------------------------------

void iSound() {
  // "I" -> single short beep
  tone(buzzerPin, 1500, 100);
}

void amAbhikSound() {
  // "am" -> short
  tone(buzzerPin, 900, 40);
  delay(50);

  // "Abhik" -> long
  tone(buzzerPin, 700, 80);
}

// ------------------------------
// LED FUNCTIONS
// ------------------------------

void clearLEDs() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(leds[i], LOW);
  }
}

void showDice(int n) {
  clearLEDs();

  if (n == 1) digitalWrite(leds[4], HIGH);

  if (n == 2) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[6], HIGH);
  }

  if (n == 3) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[4], HIGH);
    digitalWrite(leds[6], HIGH);
  }

  if (n == 4) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[5], HIGH);
    digitalWrite(leds[6], HIGH);
  }

  if (n == 5) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[4], HIGH);
    digitalWrite(leds[5], HIGH);
    digitalWrite(leds[6], HIGH);
  }

  if (n == 6) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[2], HIGH);
    digitalWrite(leds[3], HIGH);
    digitalWrite(leds[5], HIGH);
    digitalWrite(leds[6], HIGH);
  }
}
