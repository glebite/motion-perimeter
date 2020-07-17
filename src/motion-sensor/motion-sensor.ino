/*
 * PIR sensor tester
 */
 
int ledPin = 13;                // choose the pin for the LED
int inputPin1 = 2;               // choose the input pin (for PIR sensor)
int inputPin2 = 3;
int inputPin3 = 4;
int inputPin4 = 5;
int pins[4] = {inputPin1, inputPin2, inputPin3, inputPin4};
int inputPin = 0;
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
int buzzerPin = 8;
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin1, INPUT);}     // declare sensor as input
	pinMode(inputPin2, INPUT);     // declare sensor as input
	pinMode(inputPin3, INPUT);     // declare sensor as input
	pinMode(inputPin4, INPUT);     // declare sensor as input
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop(){
	for {inputPin = 0; inputPin <= 4; inputPin++} {
		sensorInputPin = inputPins[inputPin];
		val = digitalRead(sensorInputPin);  // read input value
		if (val == HIGH) {            // check if the input is HIGH
			digitalWrite(ledPin, HIGH);  // turn LED ON
			if (pirState == LOW) {
				// we have just turned on
				Serial.println("Motion detected!");
				// We only want to print on the output change, not state
				pirState = HIGH;
				digitalWrite(buzzerPin, HIGH);
				delay(5);
				digitalWrite(buzzerPin, LOW);
				delay(5);
      
			}
		} else {
			digitalWrite(ledPin, LOW); // turn LED OFF
			if (pirState == HIGH){
				// we have just turned of
				Serial.println("Motion ended!");
				// We only want to print on the output change, not state
				pirState = LOW;
			}
		}
	}
}
