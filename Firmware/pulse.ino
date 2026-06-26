#include <TFT_eSPI.h>
#include <BleKeyboard.h>
#include <ESP32Encoder.h>
#include <FastLED.h>

// --- Pin Definitions ---
#define SW_PREV 26
#define SW_NEXT 25
#define ENC_A 32
#define ENC_B 33
#define ENC_BTN 34
#define WS2812_PIN 5
#define SK6812_PIN 16
#define NUM_LEDS 4

TFT_eSPI tft = TFT_eSPI();
BleKeyboard bleKeyboard("Pulse Controller", "Arjun", 100);
ESP32Encoder encoder;
CRGB leds[NUM_LEDS];

int lastEncoderCount = 0;

void setup() {
  Serial.begin(115200);

  // Hardware pull-ups are present on the PCB, so standard INPUT is perfect
  pinMode(SW_PREV, INPUT);
  pinMode(SW_NEXT, INPUT);
  pinMode(ENC_BTN, INPUT);

  // Initialize LEDs (Using the SK6812 data line for the switch underglow)
  FastLED.addLeds<WS2812, SK6812_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(60);
  fill_solid(leds, NUM_LEDS, CRGB::SpringGreen);
  FastLED.show();

  // Initialize Screen
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.drawString("Pulse is online.", 20, 20, 4);

  // Initialize Encoder
  encoder.attachHalfQuad(ENC_A, ENC_B);
  encoder.setCount(0);

  // Start Bluetooth HID
  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    
    // Check Previous Track Button
    if (digitalRead(SW_PREV) == LOW) {
      bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
      delay(250); 
    }
    
    // Check Next Track Button
    if (digitalRead(SW_NEXT) == LOW) {
      bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
      delay(250);
    }
    
    // Check Play/Pause Encoder Button
    if (digitalRead(ENC_BTN) == LOW) {
      bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
      delay(300);
    }

    // Check Volume Knob
    int currentCount = encoder.getCount();
    if (currentCount > lastEncoderCount) {
      bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
      lastEncoderCount = currentCount;
    } else if (currentCount < lastEncoderCount) {
      bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
      lastEncoderCount = currentCount;
    }
  }
  delay(10);
}