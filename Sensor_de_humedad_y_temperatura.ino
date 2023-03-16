#include "DHT.h"
int led = 5;
int led2 = 18;
int sensorTemperatura = 4;
DHT sensor(sensorTemperatura, DHT11);
int temp, hum;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Inicializando el Sensor DHT11");
  sensor.begin();
}

void loop() {
  //Obtener temperatura
  temp = sensor.readTemperature();
  Serial.print("Temperatura = ");
  Serial.print(temp);
  Serial.print("°C");
  Serial.println();
    //Obtener húmedad del aire
  hum = sensor.readHumidity();
  Serial.print("Humedad = ");
  Serial.print(temp);
  Serial.print("%");
  Serial.println();
  delay(3000);

  if (temp>=30){
  digitalWrite(led, HIGH);
  digitalWrite(led2, LOW);

  
  } else if(temp<30){
  digitalWrite(led, LOW);
  digitalWrite(led2, HIGH);
  }

  Serial.println();

}
