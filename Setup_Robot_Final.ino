#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;
Servo Servo5;
Servo Servo6;

int IR_left=31;
int IR_right=33;

void setup() 
{ 
  int IR_left=31;
  int IR_right=33;

  Servo1.attach(47);
  Servo2.attach(46);
  Servo3.attach(45);
  Servo4.attach(49);
  Servo5.attach(41);
  Servo6.attach(44);

  Servo1.write(0);
  Servo2.write(0);
  Servo3.write(120);
  Servo4.write(20);
  Servo5.write(60);
  Servo6.write(100);
  
  motor1.setSpeed(90);                                                
  motor1.run(RELEASE);
  
  motor2.setSpeed(90);             
  motor2.run(RELEASE);              

  motor3.setSpeed(90);                                                
  motor3.run(RELEASE);

  motor4.setSpeed(90);                                                
  motor4.run(RELEASE);
}

void loop() 
{  
  home_();
  
  pick_();
  
  delay(5000);
  
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  
  if(digitalRead(IR_left)==1)
  {
    motor1.setSpeed(25);
    motor2.setSpeed(25);
    motor3.setSpeed(120);
    motor4.setSpeed(120);
  }

  if(digitalRead(IR_right)==1)
  {
    motor1.setSpeed(120);
    motor2.setSpeed(120);
    motor3.setSpeed(25);
    motor4.setSpeed(25);
  }

  if((digitalRead(IR_left)==0)&&(digitalRead(IR_right)==0))
  {
    motor1.setSpeed(90);
    motor2.setSpeed(90);
    motor3.setSpeed(90);
    motor4.setSpeed(90);
  }

  delay(10000);
  
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  
  delay(3000);
  
  place_();
  
  home2_();
  
  delay(5000);
  
  Serial.println(digitalRead(IR_right));
  delay(1000);
                       
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  
  if(digitalRead(IR_left)==1)
  {
    motor1.setSpeed(120);
    motor2.setSpeed(120);
    motor3.setSpeed(25);
    motor4.setSpeed(25);
  }

  if(digitalRead(IR_right)==1)
  {
    motor1.setSpeed(25);
    motor2.setSpeed(25);
    motor3.setSpeed(120);
    motor4.setSpeed(120);
  }

  if((digitalRead(IR_left)==0)&&(digitalRead(IR_right)==0))
  {
    motor1.setSpeed(90);
    motor2.setSpeed(90);
    motor3.setSpeed(90);
    motor4.setSpeed(90);
  }
  
  delay(10000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(3000);


}

void home_()
{
  Servo1.write(0);
  Servo2.write(0);
  Servo3.write(120);
  Servo4.write(20);
  Servo5.write(60);
  Servo6.write(100);
}

void pick_()
{

  for(int i=0;i<=60;i++)
  {
    Servo1.write(i);
    delay(65);
  }
  for(int j=0;j<=60;j++)
  {
    Servo2.write(j);
    delay(65);
  }
  for(int k=120;k>=80;k--)
  {
    Servo3.write(k);
    delay(65);
  }
  for(int n=100;n>=60;n--)
  {
    Servo6.write(n);
    delay(65);
  }
  for(int n2=60;n2<=100;n2++)
  {
    Servo6.write(n2);
    delay(65);
  }
}

void place_()
{
  for(int i3=60;i3<=120;i3++)
  {
    Servo1.write(i3);
    delay(65);
  }
  for(int n3=100;n3>=60;n3--)
  {
    Servo6.write(n3);
    delay(65);
  }
  for(int n3=60;n3<=100;n3++)
  {
    Servo6.write(n3);
    delay(65);
  }
}

void home2_()
{
  for(int j4=60;j4>=0;j4--)
  {
    Servo2.write(j4);
    delay(65);
  }
  for(int k4=80;k4<=120;k4++)
  {
    Servo3.write(k4);
    delay(65);
  }
  for(int i4=120;i4>=0;i4--)
  {
    Servo1.write(i4);
    delay(55);
  }
}
