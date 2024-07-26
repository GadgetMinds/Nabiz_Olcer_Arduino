// YouTube: GadgetMinds Türkiye //
// gadgetmindsyt@gmail.com //
// Salih Baştan / Instagram: @salihbastan //

#include <PulseSensorPlayground.h>

const int PulseWire = A0;       
const int LED13 = 13;           
int Threshold = 512;           

PulseSensorPlayground pulseSensor;

void setup() {
  Serial.begin(9600);

  // Nabız sensörü ayarları
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED13);      
  pulseSensor.setThreshold(Threshold);  

  // Sensörün çalışıp çalışmadığını kontrol etme
  if (pulseSensor.begin()) {
    Serial.println("Nabız sensörü başlatıldı.");
  } else {
    Serial.println("Nabız sensörü başlatılamadı.");
  }
}

void loop() {
  int myBPM = pulseSensor.getBeatsPerMinute();  

  // Analog girişten ham veriyi okuma ve yazdırma
  //int sensorValue = analogRead(PulseWire);
  //Serial.print("Değer: ");
  //Serial.println(sensorValue);

  // Atış algılandığında yapılacak işlemler
  if (pulseSensor.sawStartOfBeat()) {          
    Serial.println("Atış algılandı!");
    Serial.print("BPM: ");
    Serial.println(myBPM);                  
    digitalWrite(LED13, HIGH); // LED'i yak
  } else {
    digitalWrite(LED13, LOW);  // LED'i söndür
  }

  delay(20);
}
