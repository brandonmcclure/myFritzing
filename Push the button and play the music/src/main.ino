/*

*/
#include "pitches.h"
    // constants won't change. Used here to set a pin number:
const int ledPin =  LED_BUILTIN;// the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
int PlaySong = 0;
const int buttonPin = 2;     // the number of the pushbutton pin
const int speakerPin = 8;     // the number of the Speaker pin
const int durationModifier = 1.00;
int buttonState = 0;         // variable for reading the pushbutton status

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};


void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

}

void loop() {
    
    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);
    
    if (buttonState == HIGH){
      ledState = HIGH;
      // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
      PlayTune();
      delay(1000);
    }
    else{
      ledState = LOW;
      // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
    }
    
}

void PlayTune(){
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(speakerPin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * durationModifier;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerPin);
  }
}

