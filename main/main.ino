//Aplicatia preia informatii din aer(temperatura, umiditatea, calitatea aerului) si le trimite prin bluetooth pe smarphone(aplicatia bluetooth terminal) 

//biblioteci
#include "BluetoothSerial.h"
#include "DHT.h"




//definire detalii senzor
String locatieDevice="Room1";

//definire sensor calitate aer + variabile
int pinSenzorAer = 35;
float senzorAer;
float umiditate;
float temperatura;
String temperatureString = "";
String umiditateString="";
String calitateAerString="";

//definire sensor DHT22(temperatura+umiditate) +  variabile
#define DHTPIN 4 
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);



//definire obiecte Bluetooth
BluetoothSerial SerialBT;
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif


void setup() {
//pornire senzori umiditate+aer:
  dht.begin();
//pornire terminal pc pentru debug:
  Serial.begin(115200);
//setare nume aparat bluetooth:
  SerialBT.begin("ESP32");
//afisare in terminalul PC caa setarile initiale au fost efectuate:
  Serial.println("Aparatul este gata de imperecheat cu smarphone-ul");
}

void loop() {
//delay de 10 secunde la fiecare iteratie:
  delay(10000);
//apelare functie de citire a informatiilor receptate de senzorului de calitate al aerului:
  CitireSenzorAer();
//apelare functie de citire a informatiilor receptate de senzori de umiditate si temperatura:
  CitireDHTSensors();
//apelarea functiei prin care se trimit informatiile catre telefon:
  trimitereParametriiBluetooth();
}





void trimitereParametriiBluetooth(){
  umiditateString= "umiditate: "+ String(umiditate)+" %";
  temperatureString = "temperatura: "+String(temperatura)+" *C";
  calitateAerString = "calitate aer: "+String(senzorAer)+ "/900";
  Serial.println(senzorAer);
    Serial.println(senzorAer);

    Serial.println(calitateAerString);

  SerialBT.println(temperatureString);
  SerialBT.println(umiditateString);
  SerialBT.println(calitateAerString);
  SerialBT.println();
  SerialBT.println();
}

void CitireSenzorAer(){
  senzorAer=analogRead(pinSenzorAer);
}

void CitireDHTSensors(){
umiditate= dht.readHumidity();
temperatura = dht.readTemperature();

}
