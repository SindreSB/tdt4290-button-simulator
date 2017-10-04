#include "utils.h"
#include "constants.h"
#include "programs.h"


int selectedProgram = 1;

int selectButtonState = HIGH;
int lastSelectButtonState = HIGH;
unsigned long lastDebounceTimeSelectButton = 0;  // the last time the output pin was toggled

int runButtonState = HIGH;
int lastRunButtonState = HIGH;
unsigned long lastDebounceTimeRunButton = 0;

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers


void setup() {
  // put your setup code here, to run once:
  // Set ouput mode on led pins (pin 8 through 12)
  for(int i = 8; i <= 12; i++) {
    pinMode(i, OUTPUT);
    turnLedOff(i);
  }

  // Set pinmode on buttons
  pinMode(SELECT_BUTTON_PIN, INPUT);
  digitalWrite(SELECT_BUTTON_PIN, HIGH);
  pinMode(RUN_BUTTON_PIN, INPUT);
  digitalWrite(RUN_BUTTON_PIN, HIGH);

  // Set pinmodes on the weapon outputs
  pinMode(WEAPON_1_PIN, OUTPUT);
  pinMode(WEAPON_2_PIN, OUTPUT);

  // Write a low as default value
  digitalWrite(WEAPON_1_PIN, LOW);
  digitalWrite(WEAPON_2_PIN, LOW);


  // Set initial program to program one
  selectedProgram = 1;

  // Ensure the leds reflect the first program
  updateProgramLEDs(selectedProgram);
}

void loop() {
  readSelectionButton();
  readRunButton();
}


void increaseProgramSelection(){
  // We'll only allow programs 1 through 15
  selectedProgram++; 
  if(selectedProgram == 16){
    selectedProgram = 1;
  }
  updateProgramLEDs(selectedProgram);
}

void readSelectionButton() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(SELECT_BUTTON_PIN);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastSelectButtonState) {
    // reset the debouncing timer
    lastDebounceTimeSelectButton = millis();
  }

  if ((millis() - lastDebounceTimeSelectButton) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != selectButtonState) {
      selectButtonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (selectButtonState == HIGH) {
        // HERE IS ACTUAL TRUE PRESS
        increaseProgramSelection();        
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastSelectButtonState = reading;
}

void readRunButton() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(RUN_BUTTON_PIN);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastRunButtonState) {
    // reset the debouncing timer
    lastDebounceTimeRunButton = millis();
  }

  if ((millis() - lastDebounceTimeRunButton) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != runButtonState) {
      runButtonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (runButtonState == HIGH) {
        // HERE IS ACTUAL TRUE PRESS
        // RUN PROGRAM
        digitalWrite(STATUS_LED_PIN, HIGH);   // sets the LED on
        runTestProgram(selectedProgram);
        digitalWrite(STATUS_LED_PIN, LOW);    // sets the LED off     
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastRunButtonState = reading;
}

void runTestProgram(int program){
    switch (program) {
        case 1:
            programOne();
            break;
        case 2:
            programTwo();
            break;
		case 3:
			programThree();
			break;
		case 4:
			programFour();
			break;
        default:
            break;
    }
}
