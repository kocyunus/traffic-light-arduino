/*  Trafik Işıkları – R → Y → G → Y → R
    LED pinleri:
        0 : KIRMIZI   (RX hattı!)
        1 : SARI      (TX hattı!)
        2 : YEŞİL
    Her adım = 2000 ms
*/

const byte RED_PIN    = 0;
const byte YELLOW_PIN = 1;
const byte GREEN_PIN  = 2;

const byte SEQ[]  = {RED_PIN, YELLOW_PIN, GREEN_PIN, YELLOW_PIN}; // 4 adım
const byte STEPS  = sizeof(SEQ);
const unsigned long STEP_MS = 2000UL;  // 2 s

void setup() {
  pinMode(RED_PIN,    OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN,  OUTPUT);

  // Başlangıçta kırmızı
  digitalWrite(RED_PIN, HIGH);
}

void loop() {
  static byte idx = 0;               // SEQ konumu
  static unsigned long t0 = millis(); 

  if (millis() - t0 >= STEP_MS) {    // 2 s doldu mu?
    // Mevcut ışığı söndür
    digitalWrite(SEQ[idx], LOW);

    // Sıradaki adıma geç
    idx = (idx + 1) % STEPS;

    // Yeni ışığı yak
    digitalWrite(SEQ[idx], HIGH);

    // Zaman damgasını güncelle
    t0 = millis();
  }
}
