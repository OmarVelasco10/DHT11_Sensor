// Incluimos librería
#include <DHT.h>
 
// Definimos el pin digital donde se conecta el sensor
#define DHTPIN 2
// Dependiendo del tipo de sensor
#define DHTTYPE DHT11
 
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // Inicializamos comunicación serie
  Serial.begin(9600);
 
  // Comenzamos el sensor DHT
  dht.begin();
}

void loop() {
    // Esperamos 5 segundos entre medidas
  delay(5000);
 

  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();

  float kelvin = t + 273.15;
  // Leemos la temperatura en grados Fahrenheit
  float f = dht.readTemperature(true);
 
  // Comprobamos si ha habido algún error en la lectura
  if (isnan(kelvin) || isnan(t) || isnan(f)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }
 
  // Calcular el índice de calor en Fahrenheit
  float hif = dht.computeHeatIndex(f);
  // Calcular el índice de calor en grados centígrados
  float hic = dht.computeHeatIndex(t,  false);
  Serial.print("Temperatura: ");

  Serial.print(t);
  Serial.print(" *C   ");
  
  Serial.print(kelvin);
  Serial.print("*K   ");
  
 
  Serial.print(f);
  Serial.print(" *F");
  Serial.println("");

 
}
