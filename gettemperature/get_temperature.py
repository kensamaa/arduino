import serial
from datetime import datetime
import json

#so the main format of the data is this {ldr;temperatur;humidity}
def write_ligne(data):
    file=open("./data.txt",mode="a");
    file.write(data+'\n');
    file.close();

def clean_it(data):
    dataa=data.replace('\r','');
    dataa=dataa.replace('\n','');
    dataa=dataa.replace('b','');
    dataa=dataa[1:16]
    return dataa
def get_data(the_list):
    with open("./data.txt") as file:
        for line in file:
            line = line.strip() #preprocess line
            the_list.append(line)

print("start of the program");

try:
    arduino=serial.Serial("COM9",timeout=1);
except:
    print('please check the port');

#initialise variable
rawdata=[];

#receive the data and storing it in a list
#main
while True:
    now = datetime.now();
    dt_string = now.strftime("%d/%m/%Y;%H:%M:%S");#set format of the date
    data=str(arduino.readline());#getting the info from the arduino
    if(len(data)>14):
        
        data=clean_it(data);
        #print(data);
        data+=";"+dt_string;#adding the date
        #separated=data.split(";");
        """x = {
            "luminosite": separated[0],
            "temperature": separated[1],
            "humidite": separated[2],
            "date":str(separated[3]+separated[4])
            }
        varjson= json.dumps(x);"""
        #rawdata.append(data);#append it in the list
        write_ligne(data);#add it to the file
        print(data);
    
