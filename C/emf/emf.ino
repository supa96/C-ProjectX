#include <string.h>

int inPin = 4;
int val = 0;                
int red = 11; 
int yellow = 10; 
int green = 9;
int brightness = 255;  
int buzzer = 7; 
int readings[15];     
int limit = 15;
int index = 0;
int total = 0;
int average;

void setup() { 
  Serial.begin(9600);  
  for (int i = 0; i < 15; i++) { 
    readings[i] = 0;
    
  }
 
} 

void loop() {
  
  val = analogRead(inPin);     
 
                                                                 
  if(val >= 1){
    
    val = constrain(val, 1, limit);                                                    
    val = map(val, 1, limit, 1, 1023);        

    total -= readings[index]; 
    readings[index] = val; 
    total += readings[index];
    index = (index + 1); 

    if (index >= 15){ 
      index = 0;
    } 
    average = total / 15; 

    if (average >= 1023){
      ledG(); 
      Serial.print("NO EMF IS FOUND");
    } 

    else if (average > 800 && average < 1000){ 
      ledY(); 
      Serial.print("EMF IS FOUND IN THE NEARBY AREA");
    } 

    else if ( average <= 800){ 
      ledR();
      Serial.print("HIGH EMF IS FOUND");
    }
    Serial.print("Voltage: "); 
    Serial.println(abs((average*5/1023.0)-5));
      
  } 
} 

void ledG(){ 
  analogWrite(green, 255);
  analogWrite(yellow, 0); 
  analogWrite(red, 0);
} 

void ledY(){
  analogWrite(green, 255); 
  analogWrite(yellow, 255);
  analogWrite(red, 0);
} 

void ledR(){
  analogWrite(green, 255); 
  analogWrite(yellow, 255); 
  analogWrite(red, 255);
}


     
                                         
                                                             
    
    
   
                                                                 
                 



