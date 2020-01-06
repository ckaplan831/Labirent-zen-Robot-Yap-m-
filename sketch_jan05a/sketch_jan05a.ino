const int trigPin1 = 11; // orta sensör

const int echoPin1 = 10; // orta sensör

const int trigPin2 = A3;  // sağ sensör

const int echoPin2 = A4; // sağ sensör

const int trigPin3 = A2; // sol sensör

const int echoPin3 = A5; // sol sensör

const int in1 = 9; // motor 1 ileri 

const int in2 = 8; // motor 1 geri

const int in3 = 4; // motor 2 ileri

const int in4 = 3; // motor 2 geri

const int enA = 5; // motor 1 hız 

const int enB = 6; // motor 2 hız 

#define PWM 150 // motorlarımızın hızları

#define DIS 6 // sensörun gorus mesafesi
void setup() 

{

 pinMode(trigPin1, OUTPUT); // cıkış olarak 

 pinMode(echoPin1, INPUT);  // giriş olarak

 

 pinMode(trigPin2, OUTPUT);

 pinMode(echoPin2, INPUT);

 pinMode(trigPin3, OUTPUT);

 pinMode(echoPin3, INPUT);

 

 pinMode (in1, OUTPUT);

 pinMode (in2, OUTPUT);

 pinMode (in3, OUTPUT);

 pinMode (in4, OUTPUT); // çıkış olarak 

 pinMode (enA, OUTPUT);

 pinMode (enB, OUTPUT);

}


void loop()

{ 

 if ( FrontSensor() < DIS && RightSensor () <DIS && LeftSensor 

()<DIS) 
 {

        turn_right (); 

        delay(3000);

//then reverse

 }

 else if (FrontSensor() <DIS && RightSensor () <DIS && LeftSensor 

()>DIS) 

 {

 turn_left (); 



 }

 else if (FrontSensor() <DIS && RightSensor () >DIS && LeftSensor 

()<DIS) 
    {

 turn_right (); 



 }

 else if (FrontSensor() <DIS && RightSensor () >DIS && LeftSensor 

()>DIS) 

 {

 turn_right (); 



 }

 else if (FrontSensor() >DIS && RightSensor () >DIS && LeftSensor 

()<DIS) 

 {

 turn_right (); 



 delay(180);

 forward();

 }

 else if (FrontSensor() >DIS && RightSensor () <DIS && LeftSensor 

()>DIS) 

 {

 turn_left (); 



 delay(180);

 forward();

 }

 else 

 {

 forward();

 }

}

void forward ()

{

 digitalWrite(in1, HIGH);

 digitalWrite(in2, LOW);

 digitalWrite(in3, HIGH);

 digitalWrite(in4, LOW);

 analogWrite(enA, PWM); 

 analogWrite(enB, PWM);

}

void turn_left () 

{

 digitalWrite(in1, HIGH);

 digitalWrite(in2, LOW);

 digitalWrite(in3, LOW);

 digitalWrite(in4, HIGH);

 analogWrite(enA, PWM); 

 analogWrite(enB, PWM);

}

void turn_right () 

{

 digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);

 digitalWrite(in3, HIGH);

 digitalWrite(in4, LOW);

 analogWrite(enA, PWM);

 analogWrite(enB, PWM);

}

void reverse ()

{

 digitalWrite(in1, LOW);

 digitalWrite(in2, HIGH);

 digitalWrite(in3, LOW);

 digitalWrite(in4, HIGH);

 analogWrite(enA, PWM);

 analogWrite(enB, PWM);

}

void stop()

{

 digitalWrite(in1, LOW);

 digitalWrite(in2, LOW);

 digitalWrite(in3, LOW);

 digitalWrite(in4, LOW);

 analogWrite(enA, LOW);

 analogWrite(enB, LOW);

}

long FrontSensor ()

{

long dur;

 digitalWrite(trigPin1, LOW); 

 delayMicroseconds(5); 

 digitalWrite(trigPin1, HIGH);

 delayMicroseconds(10); 

 digitalWrite(trigPin1, LOW);

 dur = pulseIn(echoPin1, HIGH);

 return (dur/30);

}

long RightSensor () 

{

long dur;

 digitalWrite(trigPin2, LOW);

 delayMicroseconds(5); 

 digitalWrite(trigPin2, HIGH);

 delayMicroseconds(10); 
 
 digitalWrite(trigPin2, LOW);

 dur = pulseIn(echoPin2, HIGH);

 return (dur/62);

}

long LeftSensor ()    
{

long dur;

 digitalWrite(trigPin3, LOW); 

 delayMicroseconds(5); 

 digitalWrite(trigPin3, HIGH);

 delayMicroseconds(10); 

 digitalWrite(trigPin3, LOW);

 dur = pulseIn(echoPin3, HIGH);

 return (dur/50);

}
