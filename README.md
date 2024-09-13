# IoT Sensor Data Monitor with ThingSpeak

Este projeto visa monitorar e enviar dados de sensores ambientais, como temperatura, umidade, pressão atmosférica e altitude, para a plataforma **ThingSpeak** usando uma placa **ESP32**. A leitura dos dados é feita a partir de sensores **DHT11** (umidade e temperatura) e **BMP280** (pressão e altitude), permitindo o monitoramento remoto através da internet.

## Exemplo de Canal em Funcionamento
- https://thingspeak.com/channels/415483

## Funcionalidades

- **Monitoramento de Temperatura**: Coleta dados de temperatura em graus Celsius do sensor DHT11.
- **Monitoramento de Umidade**: Mede a umidade relativa do ar usando o sensor DHT11.
- **Monitoramento de Pressão Atmosférica**: Usa o sensor BMP280 para medir a pressão atmosférica em hPa.
- **Monitoramento de Altitude**: Calcula a altitude relativa ao nível do mar usando o sensor BMP280.
- **Upload de Dados para ThingSpeak**: Envia os dados coletados para o ThingSpeak em intervalos regulares, onde podem ser visualizados graficamente e analisados em tempo real.

## Pré-requisitos

Antes de começar, certifique-se de ter os seguintes itens:

- **ESP32** (ou ESP8266)
- **Sensor DHT11** (para medir temperatura e umidade)
- **Sensor BMP280** (para medir pressão atmosférica e altitude)
- **Conta no ThingSpeak** (para visualizar os dados enviados)
- **Conexão Wi-Fi** com SSID e senha

## Bibliotecas Necessárias

Certifique-se de que as seguintes bibliotecas estejam instaladas no seu ambiente de desenvolvimento Arduino IDE:

- **WiFi.h**: Para conectar o ESP32 à rede Wi-Fi.
- **ThingSpeak.h**: Para enviar dados ao ThingSpeak.
- **Adafruit BMP280**: Para ler os dados do sensor de pressão e altitude.
- **DHT.h**: Para ler os dados do sensor de temperatura e umidade.

### Instalação das Bibliotecas

1. Abra o Arduino IDE.
2. Vá até **Sketch > Incluir Biblioteca > Gerenciar Bibliotecas**.
3. Pesquise por `ThingSpeak`, `Adafruit BMP280`, `DHT Sensor Library` e instale todas elas.
4. Ou extraia as bibliotecas do arquivo .rar na pasta Documentos\Arduino\libraries
