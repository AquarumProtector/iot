# **AquarumProtector IoT - Monitoramento de Qualidade da Água**

## **Descrição**
Aquarum Protector é um projeto que permite aos usuários verificar e marcar locais de fontes naturais (rios, lagos, nascentes, represas etc.) como potáveis ou contaminados. O objetivo é oferecer uma solução simples e eficaz para identificar a qualidade da água, prevenindo doenças e incentivando práticas seguras de consumo.

Este projeto implementa um sistema de monitoramento de qualidade da água utilizando **Arduino**, sensores e um **display LCD**. O sistema é composto por:

- **Sensor de pH** para medir a acidez ou alcalinidade da água.
- **Sensor de turbidez** para medir a transparência da água, indicando a presença de partículas em suspensão.
- **Sensor de temperatura DHT22** para medir a temperatura da água.
- **Display LCD 16x2** para exibir a condição da água.
- **LEDs indicadores** (verde e vermelho) para sinalizar visualmente a condição da água.
- **Controle de LEDs**: O LED verde indica água potável e o LED vermelho indica água ruim, com base nos parâmetros medidos.

## **Tecnologias Utilizadas**

- **Arduino**: Microcontrolador responsável pelo processamento dos dados dos sensores.
- **Sensor de pH**: Mede a acidez/alcalinidade da água.
- **Sensor de Turbidez**: Mede a quantidade de partículas suspensas na água.
- **DHT22**: Sensor para medir a temperatura ambiente (da água, neste caso).
- **LCD 16x2**: Display para exibir a qualidade da água e os parâmetros de pH, turbidez e temperatura.
- **LEDs indicadores**: Sinalização visual para indicar o estado da água.
- **Wokwi**: Ambiente de desenvolvimento para programação do Arduino.

## **Materiais e Conexões**

| **Componente**           | **Pino no Arduino** | **Descrição**                                            |
|--------------------------|---------------------|----------------------------------------------------------|
| **Sensor de pH**          | A0                  | Conecte a saída analógica do sensor ao pino A0.          |
| **Sensor de turbidez**    | A1                  | Conecte a saída analógica do sensor ao pino A1.          |
| **Sensor DHT22**          | 7                   | Conecte o pino de dados do sensor DHT22 ao pino 7.       |
| **Display LCD 16x2**      | 8, 9, 10, 11, 12, 13| Conecte os pinos do display LCD conforme o código.       |
| **LED Verde**             | 3                   | Conecte o LED verde ao pino 3 do Arduino.                |
| **LED Vermelho**          | 2                   | Conecte o LED vermelho ao pino 2 do Arduino.             |

> **Nota**: Certifique-se de usar resistores de 220Ω para os LEDs para limitar a corrente.

## **Instalação e Uso**

### **Configuração no Arduino IDE**

1. **Instalar o Arduino IDE**:
   - Baixe e instale o Arduino IDE a partir do [site oficial](https://www.arduino.cc/en/software).
   - ou utilize o site Wokwi a partir do [site oficial](https://wokwi.com/projects/new/arduino-uno) 

2. **Selecionar a Placa**:
   - Abra o Arduino IDE e selecione a placa **Arduino Uno** ou a placa compatível que você está utilizando.

3. **Carregar o Código**:
   - Abra o código fornecido (arquivo `qualidade_agua.ino`).
   - Conecte o Arduino ao computador via cabo USB.
   - Clique em **Upload** para carregar o código para o Arduino.

### **Monitor Serial**

1. **Abrir Monitor Serial**:
   - Abra o **Monitor Serial** no Arduino IDE (configurado para 9600 bps).
   - Você verá as leituras dos sensores (pH, turbidez, temperatura) sendo exibidas na tela.

### **Funcionamento do Sistema**

O sistema verifica a qualidade da água com base nos seguintes parâmetros:

- **pH**: Idealmente entre 6.5 e 8.5 (água potável).
- **Turbidez**: Idealmente abaixo de 2.5 V (indicando água limpa).
- **Temperatura**: Idealmente entre 5°C e 35°C.

### **Indicadores no LCD e LEDs**

- O **LCD** exibirá a condição da água (potável ou ruim), junto com os valores de pH, turbidez e temperatura.
- O **LED verde** acenderá quando a água for potável.
- O **LED vermelho** acenderá quando a água for considerada ruim (fora dos parâmetros ideais).

## **Comandos Interativos (Opcional)**

Se desejar, você pode expandir esse projeto para incluir um menu interativo via **Serial Monitor**, similar ao projeto MottuGuard. Este menu poderia incluir opções como:

1. **Iniciar modo de monitoramento**: Começar a coleta de dados dos sensores.
2. **Exibir leituras de sensores**: Mostrar valores de pH, turbidez e temperatura no Serial Monitor.
3. **Desligar monitoramento**: Parar a coleta de dados e desativar os LEDs e o LCD.

Esses comandos podem ser implementados facilmente com funções baseadas em **Serial.read()**.

## **Resultados Esperados**

- **LCD**: Exibe "Água Potável" ou "Água Ruim", junto com os valores de pH, turbidez e temperatura.
- **LED Verde**: Acende quando a água está dentro dos parâmetros ideais (pH entre 6.5-8.5, turbidez < 2.5, temperatura entre 5°C e 35°C).
- **LED Vermelho**: Acende quando algum dos parâmetros da água está fora da faixa segura.
- **Monitor Serial**: Exibe os valores dos sensores em tempo real e informa se a água é potável ou não.

---

## **Arquitetura do Código**

O código está dividido nas seguintes partes:

1. **Leitura dos Sensores**:
   - **pH**: Calcula o pH com base na voltagem lida do sensor.
   - **Turbidez**: Mede a turbidez da água a partir da voltagem analógica do sensor.
   - **Temperatura**: Usa o sensor DHT22 para medir a temperatura ambiente.

2. **Exibição no LCD**:
   - O LCD exibe a condição da água, os valores de pH, turbidez e temperatura.

3. **Controle dos LEDs**:
   - Se a água estiver dentro dos parâmetros ideais, o LED verde acende.
   - Caso contrário, o LED vermelho acende.

4. **Fluxo Principal**:
   - O loop principal do código coleta as medições dos sensores e atualiza o LCD e os LEDs a cada 2 segundos.

---


