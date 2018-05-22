#include<Servo.h>

Servo myServo;
Servo myServos;
int posD = 0 ;
int posE = 27;

int frontD = 8;
int backD = 7;
int frontE = 10;
int backE = 11;
char key = ' ';

int led0 = 3;
int led1 = 4;

void setup() {
  Serial.begin(9600);
  pinMode(frontD,OUTPUT);
  pinMode(backD,OUTPUT);
  pinMode(frontE,OUTPUT);
  pinMode(backE,OUTPUT);
  myServo.attach(9);
  myServos.attach(5);
  pinMode(led0,OUTPUT);
  pinMode(led1,OUTPUT);
}

void loop() {
  if(Serial.available()){
    key = Serial.read();  
    
    if(key == 'W'){
      while(posD < 27 && posE >= 0){  
        myServo.write(posD++);
        myServos.write(posE--);
        delay(20);
      }  
    }
    
    if(key == 'U'){
      while(posD >= 0 && posE < 27){
        myServo.write(posD--);
        myServos.write(posE++);
        delay(20);
      }
    }
    
    if(key == 'B'){
      digitalWrite(frontD,HIGH);
      digitalWrite(frontE,HIGH);
       
      digitalWrite(led0,LOW);
      digitalWrite(led1,LOW);
    }else if(key == 'S'){
      digitalWrite(led0,HIGH);
      digitalWrite(led1,HIGH);
      digitalWrite(frontD,LOW);
      digitalWrite(frontE,LOW);
    }

    if(key == 'F'){
      digitalWrite(backD,HIGH);
      digitalWrite(backE,HIGH);
      
      digitalWrite(led0,LOW);
      digitalWrite(led1,LOW); 
    }else if(key == 'S'){
      digitalWrite(led0,HIGH);
      digitalWrite(led1,HIGH);
      digitalWrite(backD,LOW);
      digitalWrite(backE,LOW);
    }

    if(key == 'G'){
      digitalWrite(frontD,HIGH);
      digitalWrite(frontE,LOW);
      
      digitalWrite(led0,LOW);
      digitalWrite(led1,LOW);
    }

    if(key == 'I'){
      digitalWrite(frontE,HIGH);
      digitalWrite(frontD,LOW);
      
      digitalWrite(led0,LOW);
      digitalWrite(led1,LOW);
    }

    if(key == 'J'){
      digitalWrite(backE,HIGH);
      digitalWrite(backD,LOW);
      
      digitalWrite(led0,LOW);
      digitalWrite(led1,LOW);
    }

    if(key == 'H'){
      digitalWrite(backD,HIGH);
      digitalWrite(backE,LOW);
      
      digitalWrite(led0,LOW);
      digitalWrite(led1,LOW);
    }

    if(key == 'L'){
      digitalWrite(frontD,HIGH);
      digitalWrite(backE,HIGH);
      
      digitalWrite(led0,LOW);
      digitalWrite(led1,LOW);
    }    

    if(key == 'R'){
      digitalWrite(frontE,HIGH);
      digitalWrite(backD,HIGH);
      
      digitalWrite(led0,LOW);
      digitalWrite(led1,LOW);
    }    
  }
}
