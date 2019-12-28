int ldr1=A0;
int ldr2=A1;
const int ld2=2;
const int ld3=3;
void setup() {
  // put your setup code here, to run once:
pinMode(ld2,OUTPUT);
pinMode(ld3,OUTPUT);
pinMode(ldr1,INPUT);
pinMode(ldr2,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int ldr1statu=analogRead(ldr1);
int ldr2statu=analogRead(ldr2);

if(ldr1statu>ldr2statu){
  digitalWrite(ld2,HIGH);
  digitalWrite(ld3,LOW);
  Serial.print("light at the left side");
}
else{
  digitalWrite(ld3,HIGH);
  digitalWrite(ld2,LOW);
  Serial.print("light at the right side");
}
Serial.print("\n");
Serial.print("\n");
Serial.print(ldr1statu);
Serial.print("\n");
Serial.print("**********");
Serial.println(ldr2statu);






}
