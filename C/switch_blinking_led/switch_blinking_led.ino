const int buttonPin = 2;     
const int ledPinR =  13; 
const int ledPinG = 12;   
int buttonState; 


     

void setup() {
  
  pinMode(ledPinR, OUTPUT); 
  pinMode(ledPinG, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {  
   

    
    
  
  
  buttonState = digitalRead(buttonPin); 
  if (buttonState == HIGH) {
    
    digitalWrite(ledPinG, HIGH); 
    digitalWrite(ledPinR, LOW );
  } else {
    
    digitalWrite(ledPinG, LOW); 
    digitalWrite(ledPinR, HIGH);
  }
 }


