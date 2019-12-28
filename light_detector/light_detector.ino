const int l2 =2;
const int l3 =3;
const int ldr =A0;
void setup() {
  // put your setup code here, to run once:
pinMode(l2,OUTPUT);
    pinMode(l3,OUTPUT);
    Serial.begin(9600);
    pinMode(ldr,INPUT);
}

void loop() {
  int ldrstatus= analogRead(ldr);

  if(ldrstatus<=300){
    digitalWrite(l2,HIGH);
    digitalWrite(l3,HIGH);
    Serial.print("LIGH OFFF");
  }
  else{
    digitalWrite(l2,LOW);
    digitalWrite(l3,LOW);
     Serial.print("LIGH ONNN");
    
  }
  Serial.print("\n");
  delay(500);
  
  // put your main code here, to run repeatedly:

}
