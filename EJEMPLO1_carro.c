#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
 
#define TRUE 1
 
#define TRIG 5
#define ECHO 6
#define motor1Pin1 7
#define motor1Pin2 8
#define motor2Pin1 9
#define motor2Pin2 10
#define pwm1       2
#define pwm2       3
void setup() {
        wiringPiSetup();
        pinMode(TRIG, OUTPUT);
        pinMode(ECHO, INPUT);
		pinMode(motor1Pin1, OUTPUT);
		pinMode(motor1Pin2, OUTPUT);
		pinMode(motor2Pin1, OUTPUT);
		pinMode(motor2Pin2, OUTPUT);
 
 
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
 
        return distance;
}
 
int main(void) {
        setup();
 
        if(distancia > 15 ){
		analogWrite (pwm1,100);
		digitalWrite(motor1Pin1, HIGH);
		digitalWrite(motor1Pin2, LOW);
		digitalWrite(motor2Pin1, lOW);
		digitalWrite(motor2Pin1, LOW);
		}
		
		if(distancia < 15 ){
		analogWrite (pwm2,100);
		digitalWrite(motor1Pin1, lOW);
		digitalWrite(motor1Pin2, LOW);
		digitalWrite(motor2Pin1, HIGH);
		digitalWrite(motor2Pin1, LOW);
		}
 
 
        return 0;