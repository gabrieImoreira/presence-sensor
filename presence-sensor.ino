
int ledPin = 13;                // definindo pino do led
int inputSensor = 2;               // pino do sensor
int control = LOW;             // we start, assuming no motion detected
int val = 0;                    // variável que vai ler o status do pino
int buzzer = 10;           // pino do buzzer

void setup() {
  pinMode(ledPin, OUTPUT);      // led como output
  pinMode(inputSensor, INPUT);     // sensor como output
  pinMode(buzzer, OUTPUT);		// buzzer como output
  Serial.begin(9600);
}

void loop(){
  val = digitalRead(inputSensor);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    playTone(300, 160);
    delay(150);

    
    if (control == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      control = HIGH;
    }
  } else {
      digitalWrite(ledPin, LOW); // turn LED OFF
      playTone(0, 0);
      delay(300);    
      if (control == HIGH){
      // we have just turned off
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      control = LOW;
    }
  }
}
// duration in mSecs, frequency in hertz
void playTone(long duration, int freq) {
    duration *= 1000;
    int period = (1.0 / freq) * 1000000;
    long elapsed_time = 0;
    while (elapsed_time < duration) {
        digitalWrite(buzzer,HIGH);
        delayMicroseconds(period / 2);
        digitalWrite(buzzer, LOW);
        delayMicroseconds(period / 2);
        elapsed_time += (period);
    }
}