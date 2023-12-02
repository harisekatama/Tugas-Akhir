#include <Arduino.h>

//Motor Kiri
#define pwmpin1 5
#define dir1  18
#define dir2  19

//Motor kanan
#define pwmpin2 25
#define dir3 32
#define dir4 33

#define pwmChannel1  0
#define pwmChannel2  1
#define freq  15000
#define res  8

int PWM1_DutyCycle = 0;
int maxspeed = 127;


void setup() {
  // put your setup code here, to run once:
  
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(dir4,OUTPUT);
  //pinMode(pwmpin,OUTPUT);

  ledcSetup(pwmChannel1, freq, res);
  ledcSetup(pwmChannel2, freq, res);

  ledcAttachPin(pwmpin1, pwmChannel1);
  ledcAttachPin(pwmpin2, pwmChannel2);

  //ledcWrite(pwmChannel, 127);
}

void loop() {
  // put your main code here, to run repeatedly:

//MAJU
  //SOFTSTART
  while(PWM1_DutyCycle < maxspeed)
  {
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    digitalWrite(dir3, HIGH);
    digitalWrite(dir4, LOW);
    ledcWrite(pwmChannel1, PWM1_DutyCycle++);
    ledcWrite(pwmChannel2, PWM1_DutyCycle++);
    delay(10);
  }
  delay(5000);
  
  //SOFTSTOP
  while(PWM1_DutyCycle > 0)
  {
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    digitalWrite(dir3, HIGH);
    digitalWrite(dir4, LOW);
    ledcWrite(pwmChannel1, PWM1_DutyCycle--);
    ledcWrite(pwmChannel2, PWM1_DutyCycle--);
    delay(10);

  }
  delay(1000);

//MUNDUR
  while(PWM1_DutyCycle < maxspeed)
  {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    digitalWrite(dir3, LOW);
    digitalWrite(dir4, HIGH);
    ledcWrite(pwmChannel1, PWM1_DutyCycle++);
    ledcWrite(pwmChannel2, PWM1_DutyCycle++);
    delay(10);
  }
  delay(5000);
  
  //SOFTSTOP
  while(PWM1_DutyCycle > 0)
  {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    digitalWrite(dir3, LOW);
    digitalWrite(dir4, HIGH);
    ledcWrite(pwmChannel1, PWM1_DutyCycle--);
    ledcWrite(pwmChannel2, PWM1_DutyCycle--);
    delay(10);

  }
  delay(1000);

//BELOK KANAN
 while(PWM1_DutyCycle < maxspeed)
  {
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    digitalWrite(dir3, LOW);
    digitalWrite(dir4, LOW);
    ledcWrite(pwmChannel1, PWM1_DutyCycle++);
    ledcWrite(pwmChannel2, PWM1_DutyCycle++);
    delay(10);
  }
  delay(5000);
  
  //SOFTSTOP
  while(PWM1_DutyCycle > 0)
  {
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    digitalWrite(dir3, LOW);
    digitalWrite(dir4, LOW);
    ledcWrite(pwmChannel1, PWM1_DutyCycle--);
    ledcWrite(pwmChannel2, PWM1_DutyCycle--);
    delay(10);

  }
  delay(1000);

//BELOK KIRI
 while(PWM1_DutyCycle < maxspeed)
  {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, LOW);
    digitalWrite(dir3, HIGH);
    digitalWrite(dir4, LOW);
    ledcWrite(pwmChannel1, PWM1_DutyCycle++);
    ledcWrite(pwmChannel2, PWM1_DutyCycle++);
    delay(10);
  }
  delay(5000);
  
  //SOFTSTOP
  while(PWM1_DutyCycle > 0)
  {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, LOW);
    digitalWrite(dir3, HIGH);
    digitalWrite(dir4, LOW);
    ledcWrite(pwmChannel1, PWM1_DutyCycle--);
    ledcWrite(pwmChannel2, PWM1_DutyCycle--);
    delay(10);

  }
  delay(1000);

//STOP
 while(PWM1_DutyCycle < maxspeed)
  {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, LOW);
    digitalWrite(dir3, LOW);
    digitalWrite(dir4, LOW);
    ledcWrite(pwmChannel1, PWM1_DutyCycle++);
    ledcWrite(pwmChannel2, PWM1_DutyCycle++);
    delay(10);
  }
  delay(5000);
  
  //SOFTSTOP
  while(PWM1_DutyCycle > 0)
  {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, LOW);
    digitalWrite(dir3, LOW);
    digitalWrite(dir4, LOW);
    ledcWrite(pwmChannel1, PWM1_DutyCycle--);
    ledcWrite(pwmChannel2, PWM1_DutyCycle--);
    delay(10);

  }
  delay(1000);
}