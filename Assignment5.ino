/*
Evil.inc industries
Powered by Michael Lammers
*/

// Variable Definition
const int pinArray[] = {2, 3, 4, 5, 6, 7, 8, 9}; // Range on pins in the pin array
int timer = 500;                                 // This timer will change when either speedup or speeddown is pushed
int count = 0;                                   // Starting point for the array in a mathematical function, so that the scanner light function can be carried out

const int fastbutton = 12;                       // Button faster
int fastbuttonState1;                            // Button faster state 1
int fastbuttonState2 = LOW;                      // Button faster state 2

const int slowbutton = 13;                       // Button slower
int slowbuttonState1;                            // Button slower state 1
int slowbuttonState2 = LOW;                      // Button slower state 2


void checkbutton(){                                         // Function
  int fastbuttonreading = digitalRead(fastbutton);          // Define that the int fastbuttonreading = fastbutton
  int slowbuttonreading = digitalRead(slowbutton);          // Define that the int slowbuttonreading = slowbutton
  int currenttimer = digitalRead(timer);                    // Define that the int currenttimer = timert
  if (fastbuttonreading != fastbuttonState2) {              // Make it only work if fastbuttonState2 is not active
    if (fastbuttonreading != fastbuttonState1) {            // Make it only work if fastbuttonState1 is not active
      fastbuttonState1 = fastbuttonreading;
      if (fastbuttonState1 == HIGH) {                       // If fastbuttonState is high then fasten the timer
      timer = timer / 2;                                    // Make the speed Higher
      if (timer <= 0) {                                     // Prevent from the timer reaching 0 and block all communication
        timer = 1;
        }
      }
    }
  }
  if (slowbuttonreading != slowbuttonState2) {              // Make it only work if slowbuttonState2 is not active
    if (slowbuttonreading != slowbuttonState1) {            // Make it only work if slowbuttonState1 is not active
      slowbuttonState1 = slowbuttonreading;
      if (slowbuttonState1 == HIGH){                        // If slowbuttonState is high then fasten the timer
        timer = timer * 2;                                  // Make the speed Slower
      }
    }
  }
  fastbuttonState2 = fastbuttonreading;                     // Make fastbuttonreading listen to fastbuttonState2
  slowbuttonState2 = slowbuttonreading;                     // Make slowbuttonreading listen to slowbuttonState1
}

// defining the outputs
void setup(){
  pinMode(fastbutton, INPUT);                       // Defining the fastbutton as input
  pinMode(slowbutton, INPUT);                       // Defining the slowbutton as input
  for (count=0;count<8;count++) {                   // Defining the pins in the pin array as output's
    pinMode(pinArray[count], OUTPUT);
  }
  }
// starting the loop
void loop() {
  digitalWrite(pinArray[0],HIGH);             // Enableing the first led in the programm
  checkbutton();                              // Check if one of the buttons is pressed.
  delay(timer);
  checkbutton();                              // Check if one of the buttons is pressed.
  for (count=0;count<7;count++) {             // If the value of the counter is between this then...
   digitalWrite(pinArray[count], HIGH);       
   digitalWrite(pinArray[count + 1], HIGH);   // Counting up from the number
   checkbutton();                              // Check if one of the buttons is pressed.
   delay(timer);                              // This delay is need or els it will only show 1 led on
   checkbutton();                              // Check if one of the buttons is pressed.
   digitalWrite(pinArray[count], LOW);        // Turn of the led that is last in line
  }
   checkbutton();                              // Check if one of the buttons is pressed.
   delay(timer);
// there is no start value because this is already here
  for (count=7;count>0;count--) {             // Reverse the prossess
   digitalWrite(pinArray[count], HIGH);
   digitalWrite(pinArray[count - 1], HIGH);   // Counting the counter back again
   checkbutton();                              // Check if one of the buttons is pressed.
   delay(timer);                              // This delay is need or els it will only show 1 led on
   checkbutton();                              // Check if one of the buttons is pressed.
   digitalWrite(pinArray[count], LOW);
  }
  // no delay needed
}
// closing off


/* The End */
