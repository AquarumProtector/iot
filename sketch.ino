#include <DHT.h>
#include <LiquidCrystal.h>

#define PH_PIN       A0
#define TURB_PIN     A1
#define DHT_PIN      7
#define DHT_TYPE     DHT22
#define LED_GOOD     3
#define LED_BAD      2

DHT dht(DHT_PIN, DHT_TYPE);

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LED_GOOD, OUTPUT);
  pinMode(LED_BAD,  OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Iniciando...");
  delay(1000);
}

float readVoltage(int pin) {
  return analogRead(pin) * (5.0 / 1023.0);
}

float readPH() {
  float v = readVoltage(PH_PIN);
  return 7.0 + (2.5 - v) / 0.18;
}

float readTurbidity() {
  return readVoltage(TURB_PIN);
}

void loop() {
  float ph       = readPH();
  float turbV    = readTurbidity();
  float tempC    = dht.readTemperature();

  bool safePH   = (ph >= 6.5 && ph <= 8.5);
  bool safeTurb = (turbV <= 2.5);
  bool safeTemp = (tempC >= 5 && tempC <= 35);
  bool isSafe   = safePH && safeTurb && safeTemp;

  Serial.print("pH: "); Serial.print(ph,2);
  Serial.print(" | Turbidez V: "); Serial.print(turbV,2);
  Serial.print(" | Temp C: "); Serial.print(tempC,1);
  Serial.print(" => "); Serial.println(isSafe ? "POTAVEL" : "RUIM");

  digitalWrite(LED_GOOD, isSafe ? HIGH : LOW);
  digitalWrite(LED_BAD,  isSafe ? LOW  : HIGH);

  lcd.clear();
  if (isSafe) {
    lcd.setCursor(0, 0);
    lcd.print("Agua Potavel");
    lcd.setCursor(0, 1);
    lcd.print("pH:");
    lcd.print(ph,1);
    lcd.print(" T:");
    lcd.print(tempC,1);
  } else {
    lcd.setCursor(0, 0);
    lcd.print("   Agua Ruim  ");
    lcd.setCursor(0, 1);
    lcd.print("Tur:");
    lcd.print(turbV,1);
    lcd.print("U:");
  }

  delay(2000);
}
