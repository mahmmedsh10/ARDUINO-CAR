#include <AFMotor.h>
AF_DCMotor motor1(1);   
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);  
AF_DCMotor motor4(4);

volatile char val;

void left_side_forward(int speed) {
  // Left
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 

}

void right_side_forward(int speed) {
  // Right
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD); 
}

void left_side_backward(int speed) {
  // Left
  motor1.setSpeed(speed);
  motor1.run(BACKWARD);
  motor2.setSpeed(speed); 
  motor2.run(BACKWARD);
}

void right_side_backward(int speed) {
  // Right
  motor3.setSpeed(speed);
  motor3.run(BACKWARD);
  motor4.setSpeed(speed);
  motor4.run(BACKWARD); 
}

void forward(int speed) {

  left_side_forward(speed);
  right_side_forward(speed);

}

void backward(int speed) {

  left_side_backward(speed);
  right_side_backward(speed);
}

void turn_left(int speed) {
  left_side_backward(speed);
  right_side_forward(speed);gx 
}

void turn_right(int speed) {
  left_side_forward(speed);
  right_side_backward(speed);
}

void stop() {
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}

void setup(){


  val = 0;
  Serial.begin(9600);
 
}

void loop(){
 
   digitalWrite(11,0);
   int speed=255;
  if (Serial.available() > 0) {
    val = Serial.read();
  }
  Serial.println(val);
  switch (val) {
   case 'F':
       forward(speed);
    break;
   case 'B':
  {digitalWrite(12,0);
   digitalWrite(11,1);
    backward(speed);
    break;
  }
   case 'L':
   {
    turn_left(speed);
    break;}
   case 'R':
    turn_right(speed);
    break;
   case 'S':
    stop();
    break;
  }

}
