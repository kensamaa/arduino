
const int trigPin = 11;
const int echoPin = 10;

int a1=4;
int d1=5;
int ena=3;

int a2=6;
int d2=7;
int enb=9;

int max_distance=35;
float duration, distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //m1
  pinMode(a1, OUTPUT);
  pinMode(d1, OUTPUT);
   pinMode(ena, OUTPUT);
  //m2
  pinMode(a2, OUTPUT);
  pinMode(d2, OUTPUT);
   pinMode(enb, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //diferent_motor_direction(1);
  float distance;Serial.println(distance);
  same_motor_direction(1);Serial.println("gooooo");
 
 // diferent_motor_direction(1);Serial.println("stop obstacle");
  if(distance<30){
    //stop_all();
    delay(500);
    //diferent_motor_direction(1);Serial.println("stop obstacle");
    delay(1000);
  }
  else{
   // same_motor_direction(1);Serial.println("gooooo");
  }
}

void different_motor_direction(int direction){//direction means front or back
//si direction=1 then front else back
  analogWrite(ena,250);//(ena,150);
  analogWrite(enb,250);
    if(direction==1){
      digitalWrite(a1, HIGH); 
      digitalWrite(d1, LOW);
    Serial.print("go");
      digitalWrite(a2, HIGH); 
      digitalWrite(d2, LOW);
    }
    else{
      
      digitalWrite(d1, HIGH); 
      digitalWrite(a1, LOW);

      digitalWrite(d2, HIGH); 
      digitalWrite(a2, LOW);
    }

}
//to right or left
void same_motor_direction(int direction){//if directio=1 then to right  else left
   analogWrite(ena,250);
  analogWrite(enb,250);
    if(direction==1){
        digitalWrite(a1, HIGH); 
        digitalWrite(d1, LOW);

        digitalWrite(a2, LOW); 
        digitalWrite(d2, HIGH);
      }
      else{
        digitalWrite(d1, HIGH); 
        digitalWrite(a1, LOW);

        digitalWrite(d2, LOW); 
        digitalWrite(a2, HIGH);
      }
}
void stop_all(){//stop the robot
  analogWrite(ena,0);
  analogWrite(enb,0);
  digitalWrite(d2, LOW);
    digitalWrite(a1, LOW);
    digitalWrite(d1, LOW);
    digitalWrite(a2, LOW);Serial.println("stop"); 
    
}
float get_distance(){//calcul and return the distance from the obstacle
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  
  delay(100);
  return distance;

}
