#include <DHT.h>
#include <LiquidCrystal.h>

const int ldrPin = A0;

const int greenLed = 9;
const int yellowLed = 10;
const int redLed = 11;
const int buzzer = 12;

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);


LiquidCrystal lcd(7, 8, 3, 4, 5, 6);

unsigned long tempoAnterior = 0;

bool buzzerAtivo = false;
bool jaDisparou = false;

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);

  lcd.print("Sistema ON");
  delay(2000);
  lcd.clear();
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  unsigned long agora = millis();

  // -----------------------------
  // CLASSIFICACAO DA LUZ
  // -----------------------------
  String statusLuz = "";
  if (ldrValue < 400) {
    statusLuz = "ALTA";
  } else if (ldrValue < 600) {
    statusLuz = "MEDIA";
  } else {
    statusLuz = "BAIXA";
  }

  // -----------------------------
  // CLASSIFICACAO DA UMIDADE
  // -----------------------------
  String statusUmidade = "";
  if (umidade < 50) {
    statusUmidade = "BAIXA";
  } else if (umidade < 70) {
    statusUmidade = "MEDIA";
  } else {
    statusUmidade = "ALTA";
  }

  // -----------------------------
  // CLASSIFICACAO DA TEMPERATURA
  // -----------------------------
  String statusTemperatura = "";

  if (temperatura < 20.0) { 
    statusTemperatura = "BAIXA";
  } else if (temperatura < 24.0) {
    statusTemperatura = "MEDIA";
  } else {
    statusTemperatura = "ALTA"; 
  }

  // -----------------------------
  // SERIAL
  // -----------------------------
  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print(" | Umidade: ");
  Serial.print(umidade);
  Serial.print("% | Temp: ");
  Serial.print(temperatura);
  Serial.println("C");

  // -----------------------------
  // LCD e LEDs
  // -----------------------------
  lcd.clear();

  if (statusLuz == "BAIXA" && statusUmidade == "BAIXA" && statusTemperatura == "BAIXA") {
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzer, LOW);

    buzzerAtivo = false;
    jaDisparou = false;

    lcd.setCursor(0, 0);
    lcd.print("Sistema OK");
    lcd.setCursor(0, 1);
    lcd.print("Tudo normal");
  }
  // ALERTAS
  else {
    digitalWrite(greenLed, LOW);

    if (statusLuz == "MEDIA" || statusUmidade == "MEDIA" || statusTemperatura == "MEDIA") {
      digitalWrite(yellowLed, HIGH);
    } else {
      digitalWrite(yellowLed, LOW);
    }

    if (statusLuz == "ALTA" || statusUmidade == "ALTA" || statusTemperatura == "ALTA") {
      digitalWrite(redLed, HIGH);
    } else {
      digitalWrite(redLed, LOW);
    }

    lcd.setCursor(0, 0);
    if (statusLuz == "ALTA") {
      lcd.print("Alerta luz");
    } else if (statusTemperatura == "ALTA") {
      lcd.print("Alerta temp");
    } else if (statusLuz == "MEDIA") {
      lcd.print("Luz media");
    } else if (statusTemperatura == "MEDIA") {
      lcd.print("Temp media");
    } else {
      lcd.print("Luz/Temp OK");
    }

    lcd.setCursor(0, 1);
    if (statusUmidade == "ALTA") {
      lcd.print("Alta umidade");
    } else if (statusUmidade == "MEDIA") {
      lcd.print("Umidade media");
    } else {
      lcd.print("Umidade OK");
    }

    // -----------------------------
    // BUZZER
    // -----------------------------
    bool alertaAlto = (statusLuz == "ALTA" || statusUmidade == "ALTA" || statusTemperatura == "ALTA");


    if (alertaAlto && !jaDisparou) {
      digitalWrite(buzzer, HIGH);
      tempoAnterior = agora;
      buzzerAtivo = true;
      jaDisparou = true;
    }


    if (buzzerAtivo && (agora - tempoAnterior >= 3000)) {
      digitalWrite(buzzer, LOW);
      buzzerAtivo = false;
    }


    if (!alertaAlto) {
      jaDisparou = false;
    }
  }

  delay(500);
}
