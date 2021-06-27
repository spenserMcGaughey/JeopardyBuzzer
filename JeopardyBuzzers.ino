/* Jeopardy Buzzers Arduino program
* author: Spenser McGaughey
* date: 06/27/2021
*/

/* The following 7 lines define the switch inputs and LED outputs.
* The colors are arbitrary, just what I used when I first wrote the program.
* In pins are for the buttons or whatever is used as the switches. 
* Out pins are for the LEDs
*/
const int redInPin = 2; 
const int blueInPin = 4;
const int greenInPin  = 7;
const int controlPin = A0;
const int redOutPin = 8;
const int blueOutPin = 12;
const int greenOutPin = 13;

/* The following are some important variables
* buttonState variables represent the state of each button
* controlState is the state of the host's button
* lastControlState allows for keeping track of if the host's button state has changed
*/
int buttonStateR = 0;
int buttonStateB = 0;
int buttonStateG = 0;
int controlState = 0;
int lastControlState = 0;
int stateChange = 0;
int lastStateChange = 0;
unsigned long time;
unsigned long lastTime = 0;
unsigned long three = 3000.0;

void setup() {
  pinMode(redInPin, INPUT);
  pinMode(blueInPin, INPUT);
  pinMode(greenInPin, INPUT);
  pinMode(controlPin, INPUT);
  pinMode(redOutPin, OUTPUT);
  pinMode(blueOutPin, OUTPUT);
  pinMode(greenOutPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

 time = millis();
 
  buttonStateR = digitalRead(redInPin);
  buttonStateB = digitalRead(blueInPin);
  buttonStateG = digitalRead(greenInPin);
  controlState = digitalRead(controlPin);

if(controlState!=lastControlState){
   if(controlState==HIGH){
    stateChange++;
    delay(40);
    lastTime = time;
   }
   lastControlState=controlState;
}
 if(stateChange!= lastStateChange){
  if(buttonStateR==HIGH){
    digitalWrite(redOutPin, HIGH);
    digitalWrite(blueOutPin, LOW);
    digitalWrite(greenOutPin, LOW);
    delay(5000); 
    lastStateChange=stateChange;
  }
  else if(buttonStateB==HIGH){
    digitalWrite(redOutPin, LOW);
    digitalWrite(blueOutPin, HIGH);
    digitalWrite(greenOutPin, LOW);
    delay(5000);
    lastStateChange=stateChange;
  }
  else if(buttonStateG==HIGH){
    digitalWrite(redOutPin, LOW);
    digitalWrite(blueOutPin, LOW);
    digitalWrite(greenOutPin, HIGH);
    delay(5000);
    lastStateChange=stateChange;
  }
  else{
    digitalWrite(redOutPin, LOW);
    digitalWrite(blueOutPin, LOW);
    digitalWrite(greenOutPin, LOW);
  }

  // The following lines make the LEDs flash when the time is up
  if(time>=(lastTime+three)){
  digitalWrite(redOutPin, HIGH);
  digitalWrite(blueOutPin, HIGH);
  digitalWrite(greenOutPin, HIGH);
  delay(100);
  digitalWrite(redOutPin, LOW);
  digitalWrite(blueOutPin, LOW);
  digitalWrite(greenOutPin, LOW);
  delay(100);
  digitalWrite(redOutPin, HIGH);
  digitalWrite(blueOutPin, HIGH);
  digitalWrite(greenOutPin, HIGH);
  delay(100);
  lastStateChange=stateChange;
  }
  digitalWrite(redOutPin, LOW);
  digitalWrite(blueOutPin, LOW);
  digitalWrite(greenOutPin, LOW);
  
}
delay(30);
Serial.println(lastTime);
}
