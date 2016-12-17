#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h> 
#define TRIG 5
#define ECHO 6
#define M11 0
#define M12 2
#define PWM 3
#define PWM1 12
#define M21 14
#define M22 13
       

void setup() {
        wiringPiSetup();
        pinMode(TRIG, OUTPUT);
        pinMode(ECHO, INPUT);
		pinMode(M11, OUTPUT);
		pinMode(PWM, OUTPUT)
		pinMode(M12, OUTPUT);
		pinMode(M21, OUTPUT);
		pinMode(M22, OUTPUT);
		pinMode(PWM1,OUTPUT);
 
 
        //TRIG pin must start LOW
        digitalWrite(TRIG, LOW);
        delay(30);
}
 
int getCM() {
        //Send trig pulse
        digitalWrite(TRIG, HIGH);
        delayMicroseconds(20);
        digitalWrite(TRIG, LOW);
 
        //Wait for echo start
        while(digitalRead(ECHO) == LOW);
 
        //Wait for echo end
        long startTime = micros();
        while(digitalRead(ECHO) == HIGH);
        long travelTime = micros() - startTime;
 
        //Get distance in cm
        int distance = travelTime / 58;
        delay(100); 
		
		if(distance <= 300 && distance >= 35 ){
		analogWrite (PWM,100);
		digitalWrite(M11, HIGH);
		digitalWrite(M12, LOW);
		delay(50);
		digitalWrite(M11, lOW);
		digitalWrite(M12, LOW);
		}
		
		if(distance <= 30 && distance >= 1 ){
		analogWrite (PWM1,100);
		digitalWrite(M21, HIGH);
		digitalWrite(M22, LOW);
		delay(50);
		digitalWrite(M21, lOW);
		digitalWrite(M22, LOW);
		}
        
		if(distance < 30  && distance >30){
		analogWrite (PWM, 100);
		analogWrite (PWM1,100);
		digitalWrite(M11, HIGH);
		digitalWrite(M21, HIGH);
		delay(50);
		digitalWrite(M21, LOW);
		digitalWrite(M22, LOW);
		}
      return distance;
}
      int main(void){
		  setup();
		  while(1){
			  printf("Distancia: %dcm/n", getCM());
		  }
		  return 0;
	  }
	
	
	
	
