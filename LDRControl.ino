#define LDR A0
#define LED 3   // LED pinini tanımlama
int light_value; // Işık değerini ölçmek için değişken atadık.Dijital işaretlerde böyle bir değişken kullanırız genelde.
void setup() {
  pinMode(LED, OUTPUT); // LED tanımlama
  Serial.begin(9600);  
}

void loop() {
  // LDR'den değeri okumamız gerekir.
  light_value = analogRead(LDR); // LDR girişini okuyup değişkene atadık.
  Serial.println(light_value);
  delay(200);
  if (light_value > 600) {
    digitalWrite(LED, LOW); // Işık değeri 600den büyükse yakma
  }
  else if (light_value < 200) { // 600den küçükse ışığı aç
    digitalWrite(LED, HIGH);
  }
  else if (light_value >= 200 || light_value <= 600) { // Arada bir değer ise yak söndür.
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
  }
}
