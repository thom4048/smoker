// ReadThermoCouple.ino

const int ledPin = 11;
const int ledPin2 = 12;
const int motorPinF = 2;
const int motorPinB = 3;
int state = 1;
int repeat = 0;
int ledState = LOW;
long previousMillis = 0;
int motorState = 0;
byte incomingByte;


long interval =1000;

void setup() {
	pinMode(ledPin, OUTPUT);
	pinMode(ledPin2, OUTPUT);
  pinMode(motorPinF, OUTPUT);
  pinMode(motorPinB, OUTPUT);
	Serial.begin(9600);
}

void loop() {
	unsigned currentMillis = millis();
  if(currentMillis < 100 && previousMillis > 60000) { 
    previousMillis = 0;
  }
	if( currentMillis - previousMillis > interval) {
		previousMillis = currentMillis;
		
		int sensorValue1 = analogRead(A0);
		int sensorValue2 = analogRead(A1);
		int sensorValue3 = digitalRead(8);
		int sensorValue4 = analogRead(A2);
		int sensorValue5 = analogRead(A3);
		// Convert analog to voltage reading
		float voltage1 = sensorValue1 * (5.0 / 1023.0);
		float voltage2 = sensorValue2 * (5.0 / 1023.0);
		float voltage4 = sensorValue4 * (5.0 / 1023.0);
		float voltage5 = sensorValue5 * (5.0 / 1023.0);
		// print out the value you reading
		Serial.print(voltage1);
		Serial.print(",");
		Serial.print(voltage2);
		Serial.print(",");
		Serial.print(sensorValue3);
		Serial.print(",");
		Serial.print(voltage4);
		Serial.print(",");
		Serial.print(voltage5);

    if (Serial.available() > 0) {
      incomingByte = Serial.read(); // read the incoming byte:
      motorState = incomingByte - 48;
    }

   if(motorState == 0) {
      digitalWrite(motorPinF, LOW);
      digitalWrite(motorPinB, LOW);
     }
   else if(motorState == 1) {
      digitalWrite(motorPinF, HIGH);
      motorState = 0;
     }
   else if(motorState == 2) {
      digitalWrite(motorPinB, HIGH);
      motorState = 0;
     }
   }
   
}
