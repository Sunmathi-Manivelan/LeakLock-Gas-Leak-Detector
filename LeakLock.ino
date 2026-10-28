const int sensorPin = A0;
const int buzzer = 3;
const int safeLED = 8;
const int medLED = 9;
const int highLED = 10;
const int critLED = 11;

// Thresholds (0-1023)
const int MEDIUM_T = 256;
const int HIGH_T = 512;
const int CRITICAL_T = 768;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(safeLED, OUTPUT);
  pinMode(medLED, OUTPUT);
  pinMode(highLED, OUTPUT);
  pinMode(critLED, OUTPUT);
  Serial.begin(9600);
}

void allLedsOff() {
  digitalWrite(safeLED, LOW);
  digitalWrite(medLED, LOW);
  digitalWrite(highLED, LOW);
  digitalWrite(critLED, LOW);
}

void loop() {
  int value = analogRead(sensorPin);
  allLedsOff();

  if (value < MEDIUM_T) {
    // SAFE: silent, green LED
    digitalWrite(safeLED, HIGH);
    noTone(buzzer);
    Serial.print("Value: "); Serial.print(value);
    Serial.println(" -> SAFE");
    delay(200);
  }
  else if (value < HIGH_T) {
    // MEDIUM: slow beep, yellow LED
    digitalWrite(medLED, HIGH);
    Serial.print("Value: "); Serial.print(value);
    Serial.println(" -> MEDIUM");
    tone(buzzer, 1000);
    delay(300);
    noTone(buzzer);
    delay(700);
  }
  else if (value < CRITICAL_T) {
    // HIGH: fast beep, orange LED
    digitalWrite(highLED, HIGH);
    Serial.print("Value: "); Serial.print(value);
    Serial.println(" -> HIGH");
    tone(buzzer, 1500);
    delay(100);
    noTone(buzzer);
    delay(100);
  }
  else {
    // CRITICAL: siren, red LED
    digitalWrite(critLED, HIGH);
    Serial.print("Value: "); Serial.print(value);
    Serial.println(" -> CRITICAL");
    for (int f = 800; f <= 2000; f += 100) {
      tone(buzzer, f);
      delay(20);
    }
    for (int f = 2000; f >= 800; f -= 100) {
      tone(buzzer, f);
      delay(20);
    }
  }
}