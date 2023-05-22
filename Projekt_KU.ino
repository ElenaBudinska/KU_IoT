#include <ezButton.h>

#define LED_1_OUTPUT 26
#define LED_2_OUTPUT 18
#define LED_4_OUTPUT 19
#define LED_8_OUTPUT 23
#define BUTTON_INPUT 36

ezButton button(BUTTON_INPUT);
int number = 0;
int binaryNumber[4] = {0,0,0,0};

void setup() {
  pinMode(LED_1_OUTPUT, OUTPUT);
  pinMode(LED_2_OUTPUT, OUTPUT);
  pinMode(LED_4_OUTPUT, OUTPUT);
  pinMode(LED_8_OUTPUT, OUTPUT);
  pinMode(BUTTON_INPUT, INPUT_PULLUP);

  button.setDebounceTime(50);
  Serial.begin(9600);
}

void loop() {
  button.loop();

  if (button.isPressed()) {
    number += 1;

    if (number > 15) {
      number = 0;
      binaryNumber[0] = 0;
      binaryNumber[1] = 0;
      binaryNumber[2] = 0;
      binaryNumber[3] = 0;
    }

    Serial.println(number);

    int calculation = number;    
    int index = 0;

    while (calculation > 0) {
      if (calculation % 2 == 0)
        binaryNumber[index] = 0;
      else
        binaryNumber[index] = 1;
      
      index += 1;
      calculation = calculation / 2;
    }
  }  

  // 1. DIODA
  if (binaryNumber[0] == 1)
    digitalWrite(LED_1_OUTPUT, LOW);
  else
    digitalWrite(LED_1_OUTPUT, HIGH);

  // 2. DIODA
  if (binaryNumber[1] == 1)
    digitalWrite(LED_2_OUTPUT, LOW);
  else
    digitalWrite(LED_2_OUTPUT, HIGH);

  // 3. DIODA
  if (binaryNumber[2] == 1)
    digitalWrite(LED_4_OUTPUT, LOW);
  else
    digitalWrite(LED_4_OUTPUT, HIGH);

  // 4. DIODA
  if (binaryNumber[3] == 1)
    digitalWrite(LED_8_OUTPUT, LOW);
  else
    digitalWrite(LED_8_OUTPUT, HIGH);

}
