


//Constants
#define DHT11_PIN 2     // DHT 22  (AM2302) - what pin we're connected to
//const int sensorpin=A2;
//float temp;

//*****************************************dht DHT;
float hum;  //Stores humidity value
float temp; //Stores temperature value
#include <dht.h>

dht DHT;

//**************************************** ldr sensor
const int LDR = A1;
int input_val = 0;


void setup(){
    Serial.begin(9600);pinMode(LDR,INPUT);
}
void loop(){
   //temp=analogRead(sensorpin);
    //temp = temp * 0.48828125; 
    /*Serial.println(String(temp)+';'+String(time));
    delay(1000);
    time+=1;
    Serial.flush();*/
        //**********using dht
    
    hum=DHT.humidity;
    temp=DHT.temperature;
    int chk = DHT.read11(DHT11_PIN);
    //Serial.print("Temperature = ");
    input_val = analogRead(LDR);
    //Serial.print("LDR Value is: ");
    Serial.print(input_val);//the ldr luminosite values
    Serial.print(";");
    Serial.print(String(temp));//temperature
    Serial.print(";");
    Serial.print(String(hum));//humidite
    Serial.println();
    
    delay(3000);
     Serial.flush();
  }

    // dewPoint function NOAA
    // reference (1) : http://wahiduddin.net/calc/density_algorithms.htm
    // reference (2) : http://www.colorado.edu/geography/weather_station/Geog_site/about.htm
    double dewPointFast(double celsius, double humidity)
    {
     double a = 17.271;
     double b = 237.7;
     double temp = (a * celsius) / (b + celsius) + log(humidity*0.01);
     double Td = (b * temp) / (a - temp);
     return Td;
    }
