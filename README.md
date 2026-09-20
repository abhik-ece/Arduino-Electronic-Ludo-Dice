
# Arduino Electronic Ludo Dice

A simple Arduino-based electronic dice system designed for **Ludo and other board games**. The project uses **7 LEDs** to reproduce standard dice patterns from 1 to 6, a push button to start the dice roll, and a buzzer to provide sound feedback during the rolling process.

---

## Project Overview

Traditional dice can be replaced with a compact electronic dice using an Arduino, LEDs, a push button, and a buzzer.

When the user presses the button:

1. The Arduino detects the button press.
2. A short buzzer sound is generated.
3. The LEDs rapidly display randomly generated dice values.
4. The buzzer produces sound feedback during the rolling animation.
5. After the rolling sequence, a final random value from 1 to 6 is displayed.
6. The final dice value remains displayed until the next button press.

The project demonstrates basic concepts of **embedded systems, digital I/O, random number generation, LED control, and buzzer interfacing**.

---

## Key Features

- Random dice generation from **1 to 6**
- 7-LED dice display
- Push-button controlled operation
- LED-based rolling animation
- Buzzer feedback
- Final dice value display
- Arduino `random()` function
- Random seed using analog input
- Simple and low-cost hardware
- Suitable for Ludo and other board games

---

## Project Images

### Hardware Setup

![Hardware 1](images/Hardware%201.png)

![Hardware 2](images/Hardware%202.png)

### Circuit Design

![Circuit Design](images/Circuit%20Design.png)

### Circuit Design with Code

![Circuit Design with Code](images/Circuit%20Design%20with%20code.png)

---

## System Workflow

```text
             Push Button
                  |
                  v
        +-------------------+
        |      Arduino      |
        |                   |
        | Random Generator  |
        +---------+---------+
                  |
          +-------+-------+
          |               |
          v               v
     7 LED Display      Buzzer
          |
          v
   Dice Value 1 - 6
````

---

## Hardware Components

| Component                  |    Quantity |
| -------------------------- | ----------: |
| Arduino                    |           1 |
| LEDs                       |           7 |
| Push Button                |           1 |
| Buzzer                     |           1 |
| Current-Limiting Resistors |           7 |
| Breadboard                 |           1 |
| Jumper Wires               | As required |

---

## Pin Configuration

| Component   | Arduino Pin |
| ----------- | ----------: |
| LED 1       |          D2 |
| LED 2       |          D3 |
| LED 3       |          D4 |
| LED 4       |          D5 |
| LED 5       |          D6 |
| LED 6       |          D7 |
| LED 7       |         D11 |
| Push Button |          D8 |
| Buzzer      |         D10 |
| Random Seed |          A0 |

---

## LED Arrangement

The seven LEDs are arranged in a **3×3 dice-style layout**.

```text
D2                 D7
●                   ●


D4        D6        D5
●         ●         ●


D3                 D11
●                   ●
```

### LED Position Mapping

| Position     | Arduino Pin | Array Index |
| ------------ | ----------: | ----------: |
| Top Left     |          D2 |   `leds[0]` |
| Bottom Left  |          D3 |   `leds[1]` |
| Middle Left  |          D4 |   `leds[2]` |
| Middle Right |          D5 |   `leds[3]` |
| Center       |          D6 |   `leds[4]` |
| Top Right    |          D7 |   `leds[5]` |
| Bottom Right |         D11 |   `leds[6]` |

The LED array is defined in the program as:

```cpp
int leds[] = {2, 3, 4, 5, 6, 7, 11};
```

---

## Dice Display Patterns

### Dice Value 1

```text
         
         
    ●    
         
         
```

### Dice Value 2

```text
●             


               ●
```

### Dice Value 3

```text
●


    ●


               ●
```

### Dice Value 4

```text
●                 ●


●                 ●
```

### Dice Value 5

```text
●                 ●

        ●

●                 ●
```

### Dice Value 6

```text
●                 ●
●                 ●

●                 ●
```

---

## How the Dice Works

### 1. Button Detection

The push button is connected to **D8** and configured using the Arduino's internal pull-up resistor.

```cpp
pinMode(buttonPin, INPUT_PULLUP);
```

The program detects a button press when the signal changes from HIGH to LOW.

```cpp
if (lastButtonState == HIGH && buttonState == LOW)
```

---

### 2. Button Sound

When the button is pressed, the buzzer produces a short beep.

```cpp
void iSound() {
  tone(buzzerPin, 1500, 100);
}
```

This indicates that the dice rolling process has started.

---

### 3. Random Dice Generation

The Arduino generates a random number between 1 and 6.

```cpp
random(1, 7);
```

The upper limit of the Arduino `random()` function is exclusive, so:

```text
random(1, 7)
```

produces:

```text
1
2
3
4
5
6
```

---

### 4. Rolling Animation

The dice does not immediately show the final result.

Instead, the program repeatedly generates random values:

```cpp
for (int i = 0; i < 15; i++) {
    showDice(random(1, 7));
    amAbhikSound();
    delay(70);
}
```

This creates a rapid LED animation that simulates a physical dice roll.

---

### 5. Rolling Sound

During the rolling animation, the buzzer produces two tones.

```cpp
void amAbhikSound() {

  tone(buzzerPin, 900, 40);
  delay(50);

  tone(buzzerPin, 700, 80);
}
```

These tones provide custom audio feedback during the dice rolling process.

---

### 6. Final Dice Value

After the rolling animation, the Arduino generates one final random number.

```cpp
showDice(random(1, 7));
```

The corresponding LED pattern remains displayed until the next button press.

---

## Random Seed

The program initializes the random number generator using analog input A0.

```cpp
randomSeed(analogRead(A0));
```

This provides a changing starting value for the pseudo-random number generator.

---

## LED Control Logic

The `showDice()` function first turns OFF all LEDs.

```cpp
void clearLEDs() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(leds[i], LOW);
  }
}
```

Then the required LEDs are turned ON according to the generated dice value.

For example, the value **1** uses the center LED:

```cpp
if (n == 1)
    digitalWrite(leds[4], HIGH);
```

Since:

```text
leds[4] = D6
```

D6 acts as the center LED.

For value **6**, six LEDs are activated:

```cpp
if (n == 6) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[2], HIGH);
    digitalWrite(leds[3], HIGH);
    digitalWrite(leds[5], HIGH);
    digitalWrite(leds[6], HIGH);
}
```

---

## Software

* **Programming Language:** Arduino C/C++
* **Development Environment:** Arduino IDE
* **Version Control:** Git
* **Repository Hosting:** GitHub

---

## Project Structure

```text
Arduino-Electronic-Ludo-Dice/
│
├── images/
│   ├── Circuit Design with code.png
│   ├── Circuit Design.png
│   ├── Hardware 1.png
│   └── Hardware 2.png
│
├── src/
│   └── Arduino_Electronic_Ludo_Dice.ino
│
└── README.md
```

---

## Installation and Setup

### 1. Clone the Repository

```bash
git clone https://github.com/abhik-ece/Arduino-Electronic-Ludo-Dice.git
```

### 2. Open the Project

Open the project folder in **Arduino IDE** or **VS Code**.

### 3. Open the Arduino Code

Navigate to:

```text
src/Arduino_Electronic_Ludo_Dice.ino
```

### 4. Connect the Arduino

Connect the Arduino board to your computer using USB.

### 5. Select Board

In Arduino IDE:

```text
Tools → Board
```

Select the appropriate Arduino board.

### 6. Select Port

Go to:

```text
Tools → Port
```

Select the connected Arduino COM port.

### 7. Upload

Click:

```text
Upload
```

After uploading, press the push button to start the dice.

---

## Operating Sequence

```text
Power ON
   |
   v
Arduino initializes
   |
   v
Wait for button press
   |
   v
Button pressed
   |
   v
Short buzzer beep
   |
   v
Random LED rolling
   |
   v
Rolling sound
   |
   v
Final random value
   |
   v
Display dice value
   |
   v
Wait for next button press
```

---

## Applications

This project can be used for:

* Electronic Ludo
* Digital board games
* Educational electronics
* Arduino learning
* Embedded systems demonstrations
* Interactive electronics projects
* Microcontroller programming practice

---

## Advantages

* Simple hardware
* Low component cost
* Easy to build
* Easy to modify
* No external display required
* Provides both visual and audio feedback
* Demonstrates practical Arduino programming

---

## Limitations

* The random generator is pseudo-random.
* The project currently supports a single dice.
* The final value is displayed only through LEDs.
* The buzzer provides tones rather than recorded speech.
* The circuit currently uses a breadboard-based implementation.

---

## Future Improvements

Possible future upgrades include:

* OLED or LCD display
* Rechargeable battery
* 3D-printed enclosure
* Adjustable rolling speed
* Multiple dice support
* Multiplayer score tracking
* Bluetooth connectivity
* Wi-Fi connectivity
* Custom sound effects
* Battery level monitoring
* Compact PCB design

---

## Learning Outcomes

This project demonstrates practical concepts including:

* Arduino programming
* Digital input and output
* Push-button interfacing
* Internal pull-up resistors
* LED control
* Random number generation
* Buzzer interfacing
* Functions in embedded C/C++
* Hardware-software integration
* Git and GitHub workflow

---

## Technologies Used

```text
Arduino
Arduino C/C++
Digital Electronics
LED Control
Push Button
Buzzer
Random Number Generation
Git
GitHub
```

---

## Author

**Abhik**

Electronics & Communication Engineering

---

## Repository

GitHub:

[https://github.com/abhik-ece/Arduino-Electronic-Ludo-Dice](https://github.com/abhik-ece/Arduino-Electronic-Ludo-Dice)

---

## License

This project is available for educational and personal use.

````


