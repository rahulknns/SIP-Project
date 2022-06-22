#include <Arduino.h>
#include "fft.h"
#include "encryption.h"

int x[512];
int peaks[5];
int frequencies[5];
int key;
int password[4]  = {3,30, 55, 44};
FFT X(x,512,17674.1522);

int roundTo50(int input){

  int quotient = input/50; 

 if (input - quotient*50 >= 25) 
  {
    return (quotient + 1)*50;
  }
  else
  {
    return quotient*50;
  }
  
  
}

void setup() {

  Serial.begin(9600);

  pinMode(PB1,OUTPUT);
  pinMode(PB2,OUTPUT);
  pinMode(PB10,OUTPUT);

  digitalWrite(PB1,HIGH);
  digitalWrite(PB2,HIGH);
  digitalWrite(PB10,HIGH);

  randomSeed(analogRead(PIN_A3));
  key = random(1,21);

  delay(2000);
  digitalWrite(PB2,LOW);
   tone(A0, (key*50 + 9500) );
   delay(2000);
   noTone(A0);
   digitalWrite(PB2,HIGH);
   
   for (int i = 0; i < 512; i++)
   {
      x[i] = analogRead(A1);
   }

   X.getPeaks(peaks,5);

   for (int i = 0; i < 5; i++)
   {
      frequencies[i] = ( peaks[i]*17674.1522/512 );
      frequencies[i] = roundTo50(frequencies[i]);
      Serial.println(frequencies[i]);
   }
   






   
}

void loop() {


  

   }