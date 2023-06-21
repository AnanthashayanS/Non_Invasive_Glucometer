#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);
int s = 0;
int N,p=0;  
float v,k,m,i;
void setup() {
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){ // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; 
  }
  display.display();
  delay(500); // Pause for 2 seconds
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setRotation(0);
  delay(1000);
   display.clearDisplay();
  display.setCursor(10, 20);
  display.println("Place your finger");
  display.display();
  Serial.println("Place your finger");
  delay(5000);
  s = analogRead(0);
  v=3.3*(s/950.0);
  m=252.95*(pow(v,-0.779));
  Serial.println("Glucose");
  Serial.println(m);
}

void loop() {
   display.clearDisplay();
  display.setCursor(10, 20);
  display.print("Glucose:");
  display.print(m);
  display.print(" mg/dl");
  display.display();

}