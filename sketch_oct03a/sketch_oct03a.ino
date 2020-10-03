#include <NewPing.h>
#define Trigger_pi 11
#define Echo_pi 10
#define Maximum_pi 200
#define pump 5
NewPing pi(Trigger_pi,Echo_pi,Maximum_pi);
char dem=0;
#include<Servo.h>
Servo say;
int pos=0;
void setup() {
  // put your setup code here, to run once:
say.attach(9);
pinMode(pump,OUTPUT);
Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(pi.ping_cm());
say.write(pos);
if(pi.ping_cm() > 140){
  for(pos=0; pos>90; pos++){
    say.write(pos);
    delay(100);
    digitalWrite(pump,HIGH);
    }  
}
else if(pi.ping_cm() < 80){
  for(pos=0; pos>90; pos++){
    say.write(pos); 
    delay(100);
    }
}
else if (pi.ping_cm() > 80 and pi.ping_cm() < 140){
  for(;pos<90; pos--){
    say.write(pos);
    delay(100);
    }
}
}
