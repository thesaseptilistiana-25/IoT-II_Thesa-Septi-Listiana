const int buttonPin = 4;  
const int ledPin = 5;     

int buttonState = 0;          
int lastButtonState = LOW;    
bool ledState = false;        

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && lastButtonState == LOW) {
    ledState = !ledState; 
    digitalWrite(ledPin, ledState ? HIGH : LOW);
    
    if (ledState) {
      Serial.println("LED ON (Menyala)");
    } else {
      Serial.println("LED OFF (Mati)");
    }

    delay(200); // Debounce delay untuk mencegah pantulan sinyal
  }

  lastButtonState = buttonState;
}