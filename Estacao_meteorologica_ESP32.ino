#include <WiFi.h>
#include "ThingSpeak.h"
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Definições de pinos e tipos
#define BMP_SDA 21  
#define BMP_SCL 22
#define DHTTYPE DHT11  
#define DHTPIN 4  

// Instâncias dos sensores
Adafruit_BMP280 bmp; 
DHT dht(DHTPIN, DHTTYPE);

// Credenciais da rede WiFi
const char* ssid = "SEU_SSID";   
const char* password = "SUA_SENHA";   

WiFiClient client;

// Configurações do ThingSpeak
unsigned long myChannelNumber = SEU_NUMERO_DO_CANAL;
const char * myWriteAPIKey = "SUA_API_KEY";

// Temporizador
unsigned long lastTime = 0;
const unsigned long timerDelay = 900000;  // 15 minutos

void setup() {
  Serial.begin(115200);
  delay(100);

  // Inicia o sensor BMP280
  if (!bmp.begin()) {   
    Serial.println("Sensor BMP280 não encontrado");
    while (1); // Loop infinito caso o sensor não seja encontrado
  }
  
  // Configuração do WiFi no modo estação
  WiFi.mode(WIFI_STA);
  
  // Inicializa o ThingSpeak
  ThingSpeak.begin(client);

  // Inicializa o sensor DHT11
  dht.begin();
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {
    
    // Conexão ou reconexão ao WiFi
    if (WiFi.status() != WL_CONNECTED) {
      Serial.print("Tentando conectar");
      while (WiFi.status() != WL_CONNECTED) {
        WiFi.begin(ssid, password); 
        delay(5000);     
      } 
      Serial.println("\nConectado.");
    }

    // Leitura dos sensores
    double humidity = dht.readHumidity();
    double temp = dht.readTemperature();
    double bmp_pressure = (bmp.readPressure() / 95.53); 
    double bmp_temp2 = bmp.readTemperature();  
    double bmp_alt = bmp.readAltitude(1013.25);
  
    // Exibição dos valores lidos
    Serial.printf("Temperatura (ºC): %.2f\n", temp);
    Serial.printf("Umidade (%%): %.2f\n", humidity);
    Serial.printf("Pressão (hPa): %.2f\n", bmp_pressure);
    
    // Definir os campos com os valores lidos
    ThingSpeak.setField(1, String(humidity));
    ThingSpeak.setField(2, String(temp));
    ThingSpeak.setField(3, String(bmp_pressure));
    ThingSpeak.setField(4, String(bmp_temp2));

    // Atualiza os dados no ThingSpeak
    int response = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

    if (response == 200) {
      Serial.println("Atualização do canal bem-sucedida.");
    } else {
      Serial.println("Erro ao atualizar o canal. Código HTTP: " + String(response));
    }

    // Atualiza o temporizador
    lastTime = millis();
  }
}
