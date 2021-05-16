
int ledPin = 13;                // definindo pino do led
int inputSensor = 2;               // pino do sensor
int control = LOW;             // we start, assuming no motion detected
int val = 0;                    // variável que vai ler o status do pino
int buzzer = 10;           	// pino do buzzer
int buttonPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);      // led como output
  pinMode(inputSensor, INPUT);     // sensor como output
  pinMode(buzzer, OUTPUT);		// buzzer como output
  pinMode(buttonPin, INPUT_PULLUP);	// botao como input
  Serial.begin(9600);			// start na porta serial
}

void loop(){
   //tone(buzzer,160,30);
  
  val = digitalRead(inputSensor);  // le status do sensor
  
  if (val == HIGH) {            // check se o sinal HIGH("ALTO")
   		digitalWrite(ledPin, HIGH);  // liga o led
    	acionaAlarme(30, 160);          // função que controla o buzzer
  		delay(150);					
		Serial.println("Presença detectada"); // imprime no monitor serial
  } else {                           // se não:
      digitalWrite(ledPin, LOW); // led desligado
      acionaAlarme(0, 0);           // função zerada
      delay(300);
  
  }
}
// duração em s, frequência em Hz
void acionaAlarme(long duration, int freq) {
  
    duration *= 1000000;            //definição de variaveis
    int period = (1.0 / freq) * 1000000;
    long time = 0;
    while ((time < duration) && digitalRead(buttonPin) == HIGH) { // condições pra funcionar (incluindo botão)
        digitalWrite(buzzer,HIGH); // aciona buzzer
        delayMicroseconds(period / 2); 
        digitalWrite(buzzer, LOW);
        delayMicroseconds(period / 2);
        time += (period); //incrementação do tempo
    }
}
