
float temp;
const int ld1 = 2;
const int ld2 = 3;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ld1,OUTPUT);
pinMode(ld2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
temp =  analogRead(A0);
temp = temp * 0.48828125; 
Serial.print("temperature :");
Serial.print(temp);
Serial.print("*C");
Serial.print("\n");

if(temp>18){
   digitalWrite(ld1,LOW);
  digitalWrite(ld2,HIGH);
  
}
else{
  digitalWrite(ld2,LOW);
  digitalWrite(ld1,HIGH);
  
}
Serial.print("\n");
   delay(2000);
}


